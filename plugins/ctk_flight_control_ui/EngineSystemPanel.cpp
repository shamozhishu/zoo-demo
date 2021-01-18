#include "EngineSystemPanel.h"
#include "ui_EngineSystemPanel.h"

#if (QT_VERSION >= QT_VERSION_CHECK(5,0,0))
#pragma execution_character_set("utf-8")
#endif

EngineSystemPanel::EngineSystemPanel(QWidget *parent)
	: QWidget(parent)
	, _ui(new Ui::EngineSystemPanel)
{
	_ui->setupUi(this);
}

EngineSystemPanel::~EngineSystemPanel()
{
	delete _ui;
}
