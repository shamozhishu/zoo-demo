#include "ParamCmdPanel.h"
#include "ui_ParamCmdPanel.h"

#if (QT_VERSION >= QT_VERSION_CHECK(5,0,0))
#pragma execution_character_set("utf-8")
#endif

ParamCmdPanel::ParamCmdPanel(QWidget *parent)
	: QWidget(parent)
	, _ui(new Ui::ParamCmdPanel)
{
	_ui->setupUi(this);
}

ParamCmdPanel::~ParamCmdPanel()
{
	delete _ui;
}
