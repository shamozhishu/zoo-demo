#ifndef __SYSTEM_CONFIG_PANEL_H__
#define __SYSTEM_CONFIG_PANEL_H__

#include <QWidget>

namespace Ui {
	class SystemConfigPanel;
}

class SystemConfigPanel : public QWidget
{
	Q_OBJECT
public:
	explicit SystemConfigPanel(QWidget *parent = nullptr);
	~SystemConfigPanel();

private slots:

private:
	Ui::SystemConfigPanel* _ui;
};

#endif // __SYSTEM_CONFIG_PANEL_H__
