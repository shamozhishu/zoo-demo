#include "DeviceStatePanel.h"
#include "ui_DeviceStatePanel.h"

#if (QT_VERSION >= QT_VERSION_CHECK(5,0,0))
#pragma execution_character_set("utf-8")
#endif

DeviceStatePanel::DeviceStatePanel(QWidget *parent)
	: QWidget(parent)
	, _ui(new Ui::DeviceStatePanel)
{
	_ui->setupUi(this);
}

DeviceStatePanel::~DeviceStatePanel()
{
	delete _ui;
}
