#ifndef __LINK_MONITOR_PANEL_H__
#define __LINK_MONITOR_PANEL_H__

#include <QWidget>

namespace Ui {
	class LinkMonitorPanel;
}

class LinkMonitorPanel : public QWidget
{
	Q_OBJECT
public:
	explicit LinkMonitorPanel(QWidget *parent = nullptr);
	~LinkMonitorPanel();

private slots:

private:
	Ui::LinkMonitorPanel* _ui;
};

#endif // __LINK_MONITOR_PANEL_H__
