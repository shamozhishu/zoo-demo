#include "GroundCheckPanel.h"
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include "ui_GroundCheckPanel.h"
#include "UIActivator.h"

#if (QT_VERSION >= QT_VERSION_CHECK(5,0,0))
#pragma execution_character_set("utf-8")
#endif

GroundCheckPanel::GroundCheckPanel(QWidget *parent)
	: QWidget(parent)
	, _ui(new Ui::GroundCheckPanel)
{
	_ui->setupUi(this);
}

GroundCheckPanel::~GroundCheckPanel()
{
	delete _ui;
}
