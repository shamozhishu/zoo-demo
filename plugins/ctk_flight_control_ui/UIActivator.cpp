#include "UIActivator.h"
#include <QMessageBox>
#include <QApplication>
#include <zooCmdLoader/ZooCmdLoader.h>
#include "MainWindow.h"

#if (QT_VERSION >= QT_VERSION_CHECK(5,0,0))
#pragma execution_character_set("utf-8")
#endif

ctkPluginContext* UIActivator::_pluginContext = nullptr;
UIActivator::UIActivator()
	: _mainUI(nullptr)
{
	zooCmdL_Load();
}

void UIActivator::start(ctkPluginContext* context)
{
	_pluginContext = context;

	QFile file(":/qss/Resources/qss/black.qss");
	if (file.open(QFile::ReadOnly))
	{
		QString styleSheet = QLatin1String(file.readAll());
		qApp->setStyleSheet(styleSheet);
		file.close();
	}

	_mainUI = new MainWindow;
	_mainUI->show();
}

void UIActivator::stop(ctkPluginContext* context)
{
	SAFE_DELETE(_mainUI);
	_pluginContext = nullptr;
}

void UIActivator::sendWarCmd(QString cmdline)
{
	if (!zooCmd_Send(cmdline.trimmed().toLocal8Bit()))
	{
		QMessageBox::warning(nullptr, tr("æØ∏Ê"), QString::fromLocal8Bit(zooCmd_TipMessage()));
		return;
	}

	const char* szTips = zooCmd_TipMessage();
	if (0 != strcmp(szTips, ""))
		QMessageBox::information(nullptr, tr("Ã· æ"), QString::fromLocal8Bit(szTips));
}

ctkPluginContext* UIActivator::getPluginContext()
{
	return _pluginContext;
}
