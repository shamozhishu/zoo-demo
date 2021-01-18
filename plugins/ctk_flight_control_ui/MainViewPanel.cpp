#include "MainViewPanel.h"
#include "ui_MainViewPanel.h"

#if (QT_VERSION >= QT_VERSION_CHECK(5,0,0))
#pragma execution_character_set("utf-8")
#endif

MainViewPanel::MainViewPanel(QWidget *parent)
	: QWidget(parent)
	, _ui(new Ui::MainViewPanel)
{
	_ui->setupUi(this);
	_ui->qwtPlot_side_offset->enableAxis(QwtPlot::yLeft, false);
	_ui->qwtPlot_side_offset->setAxisScale(QwtPlot::xBottom, -5, 5, 5);
	_ui->qwtPlot_height_offset->enableAxis(QwtPlot::yLeft, false);
	_ui->qwtPlot_height_offset->setAxisScale(QwtPlot::xBottom, -5, 5, 5);
	_ui->qwtPlot_speed_offset->enableAxis(QwtPlot::yLeft, false);
	_ui->qwtPlot_speed_offset->setAxisScale(QwtPlot::xBottom, -5, 5, 5);
}

MainViewPanel::~MainViewPanel()
{
	delete _ui;
}
