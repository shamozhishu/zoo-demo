#ifndef __DEVICE_MARK_PANEL_H__
#define __DEVICE_MARK_PANEL_H__

#include <QWidget>

namespace Ui {
	class DeviceMarkPanel;
}

class DeviceMarkPanel : public QWidget
{
	Q_OBJECT
public:
	explicit DeviceMarkPanel(QWidget *parent = nullptr);
	~DeviceMarkPanel();

private slots:

private:
	Ui::DeviceMarkPanel* _ui;
};

#endif // __DEVICE_MARK_PANEL_H__
