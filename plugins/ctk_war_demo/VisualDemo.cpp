#include "VisualDemo.h"
#include "DemoActivator.h"
#include <ctk_service/war/WarService.h>

VisualDemo::VisualDemo()
{
	WarService* pWarService = DemoActivator::getService<WarService>();
	if (pWarService)
	{
		pWarService->openScene(4);
		DemoActivator::sendWarCmd("home(view4)");
		DemoActivator::sendWarCmd("earth.fly(90, 30, 20000)");
	}
}

VisualDemo::~VisualDemo()
{
	WarService* pWarService = DemoActivator::getService<WarService>();
	if (pWarService)
		pWarService->closeScene();
}
