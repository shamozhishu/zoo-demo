#include "LinkMonitorPanel.h"
#include "ui_LinkMonitorPanel.h"

#if (QT_VERSION >= QT_VERSION_CHECK(5,0,0))
#pragma execution_character_set("utf-8")
#endif

LinkMonitorPanel::LinkMonitorPanel(QWidget *parent)
	: QWidget(parent)
	, _ui(new Ui::LinkMonitorPanel)
{
	_ui->setupUi(this);
}

LinkMonitorPanel::~LinkMonitorPanel()
{
	delete _ui;
}
