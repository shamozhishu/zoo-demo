#include "FlyingControlPanel.h"
#include "ui_FlyingControlPanel.h"

#if (QT_VERSION >= QT_VERSION_CHECK(5,0,0))
#pragma execution_character_set("utf-8")
#endif

FlyingControlPanel::FlyingControlPanel(QWidget *parent)
	: QWidget(parent)
	, _ui(new Ui::FlyingControlPanel)
{
	_ui->setupUi(this);
}

FlyingControlPanel::~FlyingControlPanel()
{
	delete _ui;
}
