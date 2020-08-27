#include "VisualDemo.h"
#include "DemoActivator.h"
#include <ctk_service/war/WarService.h>

VisualDemo::VisualDemo()
{
	WarService* pWarService = DemoActivator::getService<WarService>();
	if (pWarService)
		pWarService->openScene(2);
}

VisualDemo::~VisualDemo()
{
	WarService* pWarService = DemoActivator::getService<WarService>();
	if (pWarService)
		pWarService->closeScene();
}
