#ifndef __ROUTE_CMD_PANEL_H__
#define __ROUTE_CMD_PANEL_H__

#include <QWidget>

namespace Ui {
	class RouteCmdPanel;
}

class RouteCmdPanel : public QWidget
{
	Q_OBJECT
public:
	explicit RouteCmdPanel(QWidget *parent = nullptr);
	~RouteCmdPanel();

private slots:

private:
	Ui::RouteCmdPanel* _ui;
};

#endif // __ROUTE_CMD_PANEL_H__
