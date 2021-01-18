#ifndef __MAINWINDOW_H__
#define __MAINWINDOW_H__

#include <QTime>
#include <QMainWindow>
#include "PublicDefine.h"

namespace Ui {
	class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT
public:
	explicit MainWindow(QWidget *parent = nullptr);
	~MainWindow();

private slots:
	void onWinResize();
public slots:
	void onEnterFullScreen();
	void onExitFullScreen();

protected:
	void timerEvent(QTimerEvent* event);
	void mouseMoveEvent(QMouseEvent* event);
	void mousePressEvent(QMouseEvent* event);
	void mouseReleaseEvent(QMouseEvent* event);
	void mouseDoubleClickEvent(QMouseEvent* event);

private:
	int _steps;
	QTime _time;
	int _timerId;
	float _realTime;
	bool _isPressed;
	Ui::MainWindow* _ui;
	WidgetPFD* _widgetPFD;
	WidgetASI* _widgetASI;
	WidgetNAV* _widgetNAV;
	QPoint _currentPosition;
	FlightViewPanel* _viewPanel;
	LogRecordWgt* _logs[LOG_COUNT_];
};

#endif // __MAINWINDOW_H__
