#ifndef __NAV_ATTITUDE_PANEL_H__
#define __NAV_ATTITUDE_PANEL_H__

#include <QWidget>

namespace Ui {
	class NavAttitudePanel;
}

class NavAttitudePanel : public QWidget
{
	Q_OBJECT
public:
	explicit NavAttitudePanel(QWidget *parent = nullptr);
	~NavAttitudePanel();

private slots:

private:
	Ui::NavAttitudePanel* _ui;
};

#endif // __NAV_ATTITUDE_PANEL_H__
