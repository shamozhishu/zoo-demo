#include "DemoActivator.h"
#include <QMessageBox>
#include <ctk_service/UIManagerService.h>
#include <zooCmdLoader/ZooCmdLoader.h>
#include "VisualDemo.h"

// Qt5中文乱码
#if (QT_VERSION >= QT_VERSION_CHECK(5,0,0))
#pragma execution_character_set("utf-8")
#endif

ctkPluginContext* DemoActivator::_pluginContext = nullptr;
DemoActivator::DemoActivator()
	: _visualDemo(nullptr)
{
	zooCmdL_Load();
}

void DemoActivator::start(ctkPluginContext* context)
{
	_pluginContext = context;

	UIManagerService* service = DemoActivator::getService<UIManagerService>();
	if (service != Q_NULLPTR)
	{
		service->finishWindowLaunch();
		service->setWindowTitle(tr("视景演示程序"));
		_visualDemo = new VisualDemo;
	}
	else
	{
		zoo_warning(zoo::utf8ToAnsi("获取“pointer of UIManagerService”为空！").c_str());
	}
}

void DemoActivator::stop(ctkPluginContext* context)
{
	UIManagerService* service = DemoActivator::getService<UIManagerService>();
	if (service != Q_NULLPTR)
	{
		
	}
	
	SAFE_DELETE(_visualDemo);
	_pluginContext = nullptr;
}

void DemoActivator::sendWarCmd(QString cmdline)
{
	if (!zooCmd_Send(cmdline.trimmed().toLocal8Bit()))
	{
		QMessageBox::warning(nullptr, tr("警告"), QString::fromLocal8Bit(zooCmd_TipMessage()));
		return;
	}

	const char* szTips = zooCmd_TipMessage();
	if (0 != strcmp(szTips, ""))
		QMessageBox::information(nullptr, tr("提示"), QString::fromLocal8Bit(szTips));
}
