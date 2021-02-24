#ifndef __FLIGHT_VIEW_PANEL__
#define __FLIGHT_VIEW_PANEL__

#include <QWidget>
#include <QMainWindow>

namespace Ui {
	class FlightViewPanel;
}

class QHBoxLayout;
class FlightVisualWgt;
class FullScreenPanel;
class FlightViewPanel : public QWidget
{
	Q_OBJECT
public:
	explicit FlightViewPanel(QMainWindow* mainWindow, QWidget* parent = nullptr);
	~FlightViewPanel();
	void enterFullScreen();
	void exitFullScreen();

private:
	Ui::FlightViewPanel* _ui;
	QHBoxLayout* _hboxLayout;
	QMainWindow* _mainWindow;
	FlightVisualWgt* _visualWgt;
	FullScreenPanel* _fullScreenPanel;
};

#endif // __FLIGHT_VIEW_PANEL__
