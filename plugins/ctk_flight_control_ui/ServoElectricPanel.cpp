#include "ServoElectricPanel.h"
#include "ui_ServoElectricPanel.h"

#if (QT_VERSION >= QT_VERSION_CHECK(5,0,0))
#pragma execution_character_set("utf-8")
#endif

ServoElectricPanel::ServoElectricPanel(QWidget *parent)
	: QWidget(parent)
	, _ui(new Ui::ServoElectricPanel)
{
	_ui->setupUi(this);
}

ServoElectricPanel::~ServoElectricPanel()
{
	delete _ui;
}
