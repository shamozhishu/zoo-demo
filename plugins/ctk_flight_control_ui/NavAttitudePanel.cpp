#include "NavAttitudePanel.h"
#include "ui_NavAttitudePanel.h"

#if (QT_VERSION >= QT_VERSION_CHECK(5,0,0))
#pragma execution_character_set("utf-8")
#endif

NavAttitudePanel::NavAttitudePanel(QWidget *parent)
	: QWidget(parent)
	, _ui(new Ui::NavAttitudePanel)
{
	_ui->setupUi(this);
}

NavAttitudePanel::~NavAttitudePanel()
{
	delete _ui;
}
