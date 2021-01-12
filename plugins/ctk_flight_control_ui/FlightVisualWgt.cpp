#include "FlightVisualWgt.h"
#include <zooCmdLoader/ZooCmdLoader.h>
#include <ctk_service/WarService.h>
#include <vector>
#include <string>
#include <QThread>
#include <QScreen>
#include <QWindow>
#include <QLayout>
#include <QSettings>
#include <QMessageBox>
#include <QMainWindow>
#include <QApplication>
#include <QInputDialog>
#include "UIActivator.h"

// Qt5��������
#if (QT_VERSION >= QT_VERSION_CHECK(5,0,0))
#pragma execution_character_set("utf-8")
#endif

// �ڵ������߳���������Ⱦѭ��,Ŀǰ�ᵼ�³������,������ʱ������������run().
class RenderThread : public QThread
{
public:
	virtual ~RenderThread()
	{
		zooCmd_Destroy();
		wait();
	}

	void run()
	{
		zooCmd_Run();
	}
};

class CmdRegThread : public QThread
{
public:
	CmdRegThread(QStringList cmdset) : _cmdset(cmdset), _completed(false) {}
	bool isCompleted() const { return _completed; }
	QString getErrTip() const { return _errStr; }

	void init()
	{
		zooCmd_UnregisterAll();
		regCmdset();
		_completed = true;
	}

	void setCmdset(QStringList cmdset)
	{
		_completed = false;
		_cmdset = cmdset;
		_errStr = "";
	}

protected:
	void run() override
	{
		init();
	}

	void regCmdset()
	{
		int len = _cmdset.size();
		for (int i = 0; i < len; ++i)
		{
			if (!zooCmd_Register(_cmdset[i].toStdString().c_str()))
			{
				if (_errStr == "")
					_errStr = _cmdset[i];
				else
					_errStr += (QString(", ") + _cmdset[i]);
			}
		}

		if (_errStr != "")
			_errStr = QString("����[") + _errStr + "]������ʧ�ܣ�";
	}

protected:
	bool _completed;
	QString _errStr;
	QStringList _cmdset;
};

FlightVisualWgt::FlightVisualWgt(QString renderAdaName, QStringList cmdset, QString datadir /*= ""*/, QWidget* parent /*= Q_NULLPTR*/)
	: QWidget(parent)
	, _renderThread(new RenderThread)
	, _cmdRegThread(new CmdRegThread(cmdset))
{
	setMouseTracking(true);
	setFocusPolicy(Qt::ClickFocus);
	setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	zooCmdL_Load();

	QScreen* screen = windowHandle() && windowHandle()->screen() ? windowHandle()->screen() : qApp->screens().front();
	zooCmd_Destroy();
	if (zooCmd_InitW(renderAdaName.toStdString().c_str(), datadir.toStdWString().c_str()))
	{
		QWidget* pGLWgt = (QWidget*)zooCmd_Setup(width(), height(), screen->devicePixelRatio(), ZOOCMDWGT);
		if (pGLWgt)
		{
			setLayout(new QHBoxLayout);
			layout()->setMargin(0);
			layout()->addWidget(pGLWgt);

			// ��ʼ���Ӿ�����
			WarService* pWarService = UIActivator::getService<WarService>();
			if (pWarService)
				pWarService->openScene(1);

			resgisterCmdset(cmdset);
		}
		else
			QMessageBox::warning(nullptr, tr("����"), "��ʼ��GLWidget����ʧ�ܣ�");
	}
	else
		QMessageBox::warning(nullptr, tr("����"), "��ʼ��zooCmd���ʧ�ܣ�");
}

FlightVisualWgt::~FlightVisualWgt()
{
	while (_cmdRegThread->isRunning())
		QThread::sleep(1);

	delete _cmdRegThread;
	delete _renderThread;
}

HWND FlightVisualWgt::getWnd()
{
	return (HWND)winId();
}

bool FlightVisualWgt::isFocus()
{
	return isActiveWindow();
}

void FlightVisualWgt::resgisterCmdset(QStringList cmdset)
{
	_cmdRegThread->setCmdset(cmdset);
	_cmdRegThread->start();

	emit cmdRegistered();

	QString errTip = _cmdRegThread->getErrTip();
	if (errTip != "")
		QMessageBox::warning(this, tr("����"), errTip);
	else
	{
		QSettings settings(QCoreApplication::applicationDirPath() + "/config.ini", QSettings::IniFormat);
		settings.beginGroup("ZOO_CMDSET");
		settings.setValue("activecmd", cmdset);
		settings.endGroup();
	}
}

bool FlightVisualWgt::isCmdRegCompleted() const
{
	return _cmdRegThread->isCompleted();
}
