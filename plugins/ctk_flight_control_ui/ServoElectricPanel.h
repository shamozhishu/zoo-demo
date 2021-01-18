#ifndef __SERVO_ELECTRIC_PANEL_H__
#define __SERVO_ELECTRIC_PANEL_H__

#include <QWidget>

namespace Ui {
	class ServoElectricPanel;
}

class ServoElectricPanel : public QWidget
{
	Q_OBJECT
public:
	explicit ServoElectricPanel(QWidget *parent = nullptr);
	~ServoElectricPanel();

private slots:

private:
	Ui::ServoElectricPanel* _ui;
};

#endif // __SERVO_ELECTRIC_PANEL_H__
