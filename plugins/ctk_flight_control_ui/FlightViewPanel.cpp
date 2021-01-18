#include "FlightViewPanel.h"
#include "ui_FlightViewPanel.h"
#include "ui_FullScreenPanel.h"
#include "FullScreenPanel.h"
#include "FlightVisualWgt.h"
#include "UIActivator.h"
#include <QSettings>
#include <ctk_service/WarService.h>

#if (QT_VERSION >= QT_VERSION_CHECK(5,0,0))
#pragma execution_character_set("utf-8")
#endif

FlightViewPanel::FlightViewPanel(QMainWindow* mainWindow, QWidget* parent)
	: QWidget(parent)
	, _ui(new Ui::FlightViewPanel)
	, _mainWindow(mainWindow)
	, _visualWgt(nullptr)
	, _fullScreenPanel(nullptr)
{
	_ui->setupUi(this);
	QSettings settings(QCoreApplication::applicationDirPath() + "/config.ini", QSettings::IniFormat);
	settings.beginGroup("ZOO_CMDSET");
	QString datadir = settings.value("datadir").toString();
	QStringList cmdset = settings.value("activecmd").toStringList();
	settings.endGroup();
	_visualWgt = new FlightVisualWgt("zooCmd_osg", cmdset, datadir, this);
	_ui->verticalLayout->insertWidget(0, _visualWgt);
}

FlightViewPanel::~FlightViewPanel()
{
	delete _ui;
	WarService* pWarService = UIActivator::getService<WarService>();
	if (pWarService)
		pWarService->closeScene();
}

void FlightViewPanel::enterFullScreen()
{
	if (!_fullScreenPanel)
	{
		_fullScreenPanel = new FullScreenPanel;
		connect(_fullScreenPanel, SIGNAL(quitFullScreen()), _mainWindow, SLOT(onExitFullScreen()));
		_visualWgt->setParent(_fullScreenPanel->_ui->frame);
		_fullScreenPanel->_ui->verticalLayout_view->addWidget(_visualWgt);
		_fullScreenPanel->showMaximized();
		((QWidget*)parent())->setVisible(false);
	}
}

void FlightViewPanel::exitFullScreen()
{
	if (_fullScreenPanel)
	{
		_visualWgt->setParent(this);
		_ui->verticalLayout->insertWidget(0, _visualWgt);
		_fullScreenPanel->deleteLater();
		_fullScreenPanel = nullptr;
		((QWidget*)parent())->setVisible(true);
	}
}
