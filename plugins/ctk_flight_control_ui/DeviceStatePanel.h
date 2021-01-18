#ifndef __DEVICE_STATE_PANEL_H__
#define __DEVICE_STATE_PANEL_H__

#include <QWidget>

namespace Ui {
	class DeviceStatePanel;
}

class DeviceStatePanel : public QWidget
{
	Q_OBJECT
public:
	explicit DeviceStatePanel(QWidget *parent = nullptr);
	~DeviceStatePanel();

private slots:

private:
	Ui::DeviceStatePanel* _ui;
};

#endif // __DEVICE_STATE_PANEL_H__
