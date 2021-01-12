#pragma once
#include <string>
#include <vector>

using namespace std;

class WidgetPFD;
class WidgetASI;
class WidgetNAV;
class LogRecordWgt;
class FlightViewPanel;
class StatusCheckPanel;

enum ELogType
{
	CMD_LOG_ = 0,
	FAULT_LEVEL1_LOG_,
	FAULT_LEVEL2_LOG_,
	FAULT_LEVEL3_LOG_,
	LOG_COUNT_
};
