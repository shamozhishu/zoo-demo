#ifndef __FLIGHT_PARAM_PANEL__
#define __FLIGHT_PARAM_PANEL__

#include <QWidget>

namespace Ui {
	class FlightParamPanel;
}

class FlightParamPanel : public QWidget
{
	Q_OBJECT
public:
	explicit FlightParamPanel(QWidget *parent = nullptr);
	~FlightParamPanel();

private slots:

private:
	Ui::FlightParamPanel* _ui;
};

#endif // __FLIGHT_PARAM_PANEL__
