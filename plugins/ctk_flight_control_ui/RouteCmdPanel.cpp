#include "RouteCmdPanel.h"
#include "ui_RouteCmdPanel.h"

#if (QT_VERSION >= QT_VERSION_CHECK(5,0,0))
#pragma execution_character_set("utf-8")
#endif

RouteCmdPanel::RouteCmdPanel(QWidget *parent)
	: QWidget(parent)
	, _ui(new Ui::RouteCmdPanel)
{
	_ui->setupUi(this);
}

RouteCmdPanel::~RouteCmdPanel()
{
	delete _ui;
}
