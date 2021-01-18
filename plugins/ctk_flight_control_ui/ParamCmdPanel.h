#ifndef __PARAM_CMD_PANEL_H__
#define __PARAM_CMD_PANEL_H__

#include <QWidget>

namespace Ui {
	class ParamCmdPanel;
}

class ParamCmdPanel : public QWidget
{
	Q_OBJECT
public:
	explicit ParamCmdPanel(QWidget *parent = nullptr);
	~ParamCmdPanel();

private slots:

private:
	Ui::ParamCmdPanel* _ui;
};

#endif // __PARAM_CMD_PANEL_H__
