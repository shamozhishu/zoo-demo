#include "MainWindow.h"
#include <QTimer>
#include <QDateTime>
#include <QMessageBox>
#include <QMouseEvent>
#include "ui_MainWindow.h"
#include "LogRecordWgt.h"
#include "StatusCheckPanel.h"
#include "FlightParamPanel.h"
#include "FlightViewPanel.h"
#include "FlightVisualWgt.h"
#include "WidgetPFD.h"
#include "WidgetNAV.h"
#include "WidgetASI.h"

#if (QT_VERSION >= QT_VERSION_CHECK(5,0,0))
#pragma execution_character_set("utf-8")
#endif

static const char* s_titles[] = { "", " һ���澯��", " �����澯��", " �����澯��" };
static const char* s_keys[] = { "ָ������", "������Ϣ", "������Ϣ", "������Ϣ" };
static const char* s_values[] = { "����ʱ��", "������ʾ", "������ʾ", "������ʾ" };

static const char* s_keys_0[] = { "��ѯ���ߣ�ָ�������", "��ѯ���ߣ��ѷ���", "��ѯ���ߣ�ָ�������", "��ѯ���ߣ��ѷ���",
"��ѯ���ߣ�ָ�������", "��ѯ���ߣ��ѷ���", "�ɿع���ģʽ��ָ�������", "�ɿع���ģʽ���ѷ���" };
static const char* s_values_0[] = { "20-12-25 09:13:40", "20-12-25 09:13:40", "20-12-25 09:13:37", "20-12-25 09:13:37",
"20-12-25 09:13:31", "20-12-25 09:13:31", "20-12-25 09:13:15", "20-12-25 09:13:14" };

static const char* s_keys_1[] = { "��ѹ����", "ECU����" };
static const char* s_values_1[] = { "��������ѹ<22V", "������ģ��ͨѶ״̬����" };

static const char* s_keys_2[] = { "�ߵ�����", "���������ͨѶ����", "���ϵͳʧЧ", "����ѹ���쳣" };
static const char* s_values_2[] = { "�ߵ�ͨѶ״̬����", "������ͨѶ״̬����", "���ϵͳͨѶ״̬����", "����ѹ��<203kPa" };

static const char* s_keys_3[] = { "�̵����й���", "��Vβ���ƺй���", "��Vβ���ƺй���", "������ƺй���", "�Ҹ�����ƺй���" };
static const char* s_values_3[] = { "�̵�����ͨѶ״̬����", "��VβͨѶ״̬����", "��VβͨѶ״̬����", "����ͨѶ״̬����", "�Ҹ���ͨѶ״̬����" };

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
	, _ui(new Ui::MainWindow)
	, _isPressed(false) // �϶�����ĵ����־λ
	, _steps(0)
	, _timerId(0)
	, _realTime(0.0f)
{
	_ui->setupUi(this);
	_timerId = startTimer(0);
	_time.start();

	setWindowFlags(Qt::FramelessWindowHint);
	connect(_ui->pushButton_exit, SIGNAL(clicked()), this, SLOT(close()));
	connect(_ui->pushButton_min, SIGNAL(clicked()), this, SLOT(showMinimized()));
	connect(_ui->pushButton_max, SIGNAL(clicked()), this, SLOT(onWinResize()));
	connect(_ui->pushButton_fullscreen, SIGNAL(clicked()), this, SLOT(onEnterFullScreen()));
	connect(_ui->pushButton_help, &QPushButton::clicked, [this]
	{
		QMessageBox::information(this, "����", "���п��ƹ������ V1.0");
	});

	_ui->label_datetime->setText(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"));
	QTimer* pTimer = new QTimer(this);
	pTimer->start(20);
	connect(pTimer, &QTimer::timeout, [this]
	{
		_ui->label_datetime->setText(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss dddd"));
	});

	_statusCheckPanel = new StatusCheckPanel;
	_ui->verticalLayout_right->addWidget(_statusCheckPanel);

	_viewPanel = new FlightViewPanel(this);
	_ui->verticalLayout_center->addWidget(_viewPanel);
	_widgetPFD = new WidgetPFD;
	_widgetASI = new WidgetASI;
	_widgetNAV = new WidgetNAV;
	QHBoxLayout* pHLayout = new QHBoxLayout;
	pHLayout->addWidget(_widgetPFD);
	pHLayout->addWidget(_widgetASI);
	pHLayout->addWidget(_widgetNAV);
	QFrame* pFrameQfi = new QFrame;
	pFrameQfi->setLayout(pHLayout);
	_ui->verticalLayout_center->addWidget(pFrameQfi);
	_ui->verticalLayout_center->addWidget(new FlightParamPanel);

	for (int i = 0; i < LOG_COUNT_; ++i)
	{
		_logs[i] = new LogRecordWgt;
		_logs[i]->setTableHeader(s_keys[i], s_values[i]);
		_logs[i]->setTitle(s_titles[i], i == FAULT_LEVEL3_LOG_ ? QColor(255, 255, 0) : QColor(255, 0, 0));
		_ui->verticalLayout_left->addWidget(_logs[i]);
	}

	//--------------------------------------------------------------------
	// ��ʼ����ʱ����
	for (int i = 0; i < 8; ++i)
	{
		QStringList txt;
		txt << s_keys_0[i] << s_values_0[i];
		QColor txtClr = i % 2 == 0 ? QColor(0, 255, 0) : QColor(255, 255, 255);
		_logs[CMD_LOG_]->addLog(txt, txtClr);
	}

	for (int i = 0; i < 2; ++i)
	{
		QStringList txt;
		txt << s_keys_1[i] << s_values_1[i];
		_logs[FAULT_LEVEL1_LOG_]->addLog(txt, QColor(255, 0, 0));
	}

	for (int i = 0; i < 4; ++i)
	{
		QStringList txt;
		txt << s_keys_2[i] << s_values_2[i];
		_logs[FAULT_LEVEL2_LOG_]->addLog(txt, QColor(255, 0, 0));
	}

	for (int i = 0; i < 5; ++i)
	{
		QStringList txt;
		txt << s_keys_3[i] << s_values_3[i];
		_logs[FAULT_LEVEL3_LOG_]->addLog(txt, QColor(255, 255, 0));
	}
	//--------------------------------------------------------------------
}

MainWindow::~MainWindow()
{
	delete _ui;
	if (_timerId)
		killTimer(_timerId);
}

void MainWindow::onWinResize()
{
	if (isMaximized())
	{
		showNormal();
		_ui->pushButton_max->setText("��");
		_ui->pushButton_max->setToolTip("���");
	}
	else
	{
		showMaximized();
		_ui->pushButton_max->setText("��");
		_ui->pushButton_max->setToolTip("��ԭ");
	}
}

void MainWindow::onEnterFullScreen()
{
	setVisible(false);
	_viewPanel->enterFullScreen();
}

void MainWindow::onExitFullScreen()
{
	setVisible(true);
	_viewPanel->exitFullScreen();
}

void MainWindow::timerEvent(QTimerEvent* event)
{
	QMainWindow::timerEvent(event);

	float timeStep = _time.restart();
	_realTime += timeStep / 1000.0f;

	float alpha = 0.0f;
	float beta = 0.0f;
	float roll = 0.0f;
	float pitch = 0.0f;
	float heading = 0.0f;
	float slipSkid = 0.0f;
	float turnRate = 0.0f;
	float devH = 0.0f;
	float devV = 0.0f;
	float airspeed = 0.0f;
	float altitude = 0.0f;
	float pressure = 28.0f;
	float climbRate = 0.0f;
	float machNo = 0.0f;
	float adf = 0.0f;
	float dme = 0.0f;

	if (true)
	{
		alpha = 20.0f * sin(_realTime / 10.0f);
		beta = 15.0f * sin(_realTime / 10.0f);
		roll = 180.0f * sin(_realTime / 10.0f);
		pitch = 90.0f * sin(_realTime / 20.0f);
		heading = 360.0f * sin(_realTime / 40.0f);
		slipSkid = 1.0f * sin(_realTime / 10.0f);
		turnRate = 7.0f * sin(_realTime / 10.0f);
		devH = 1.0f * sin(_realTime / 20.0f);
		devV = 1.0f * sin(_realTime / 20.0f);
		airspeed = 125.0f * sin(_realTime / 40.0f) + 125.0f;
		altitude = 9000.0f * sin(_realTime / 40.0f) + 9000.0f;
		pressure = 2.0f * sin(_realTime / 20.0f) + 30.0f;
		climbRate = 650.0f * sin(_realTime / 20.0f);
		machNo = airspeed / 650.0f;
		adf = -360.0f * sin(_realTime / 50.0f);
		dme = 99.0f * sin(_realTime / 100.0f);
	}

	_widgetPFD->setFlightPathMarker(alpha, beta);
	_widgetPFD->setRoll(roll);
	_widgetPFD->setPitch(pitch);
	_widgetPFD->setSlipSkid(slipSkid);
	_widgetPFD->setTurnRate(turnRate / 6.0f);
	_widgetPFD->setDevH(devH);
	_widgetPFD->setDevV(devV);
	_widgetPFD->setHeading(heading);
	_widgetPFD->setAirspeed(airspeed);
	_widgetPFD->setMachNo(machNo);
	_widgetPFD->setAltitude(altitude);
	_widgetPFD->setPressure(pressure);
	_widgetPFD->setClimbRate(climbRate / 100.0f);
	_widgetPFD->setIdentifier("ILAX", true);
	_widgetPFD->setDistance(dme, true);

	_widgetNAV->setHeading(heading);
	_widgetNAV->setHeadingBug(0.0f);
	_widgetNAV->setCourse(0.0f);
	_widgetNAV->setBearing(adf, true);
	_widgetNAV->setDeviation(devH, true);
	_widgetNAV->setDistance(dme, true);

	_widgetASI->setAirspeed(airspeed);

	_widgetPFD->update();
	_widgetNAV->update();
	_widgetASI->update();

	_steps++;
}

void MainWindow::mouseMoveEvent(QMouseEvent* event)
{
	if (_isPressed && !isMaximized() && !isMinimized() && !isFullScreen()) // ������ƶ�ʱ�϶�����
	{
		int dx = event->pos().x() - _currentPosition.x();
		int dy = event->pos().y() - _currentPosition.y();
		move(this->pos().x() + dx, this->pos().y() + dy);
	}
}

void MainWindow::mousePressEvent(QMouseEvent* event)
{
	if (event->pos().y() < 50)
	{
		_isPressed = true;
		_currentPosition = event->pos();
	}
}

void MainWindow::mouseReleaseEvent(QMouseEvent* event)
{
	_isPressed = false;
}

void MainWindow::mouseDoubleClickEvent(QMouseEvent* event)
{
	onWinResize();
}
