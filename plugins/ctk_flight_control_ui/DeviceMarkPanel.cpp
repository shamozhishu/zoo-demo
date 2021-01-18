#include "DeviceMarkPanel.h"
#include "ui_DeviceMarkPanel.h"
#include "UIActivator.h"

#if (QT_VERSION >= QT_VERSION_CHECK(5,0,0))
#pragma execution_character_set("utf-8")
#endif

DeviceMarkPanel::DeviceMarkPanel(QWidget *parent)
	: QWidget(parent)
	, _ui(new Ui::DeviceMarkPanel)
{
	_ui->setupUi(this);
	_ui->tableWidget->setItemDelegate(new NoFocusDelegate);
	_ui->tableWidget->setColumnWidth(0, 50);
}

DeviceMarkPanel::~DeviceMarkPanel()
{
	delete _ui;
}
