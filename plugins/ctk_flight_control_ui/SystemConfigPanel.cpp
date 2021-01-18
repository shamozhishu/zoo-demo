#include "SystemConfigPanel.h"
#include "ui_SystemConfigPanel.h"

#if (QT_VERSION >= QT_VERSION_CHECK(5,0,0))
#pragma execution_character_set("utf-8")
#endif

SystemConfigPanel::SystemConfigPanel(QWidget *parent)
	: QWidget(parent)
	, _ui(new Ui::SystemConfigPanel)
{
	_ui->setupUi(this);
}

SystemConfigPanel::~SystemConfigPanel()
{
	delete _ui;
}
