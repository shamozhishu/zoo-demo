#ifndef __FLYING_CONTROL_PANEL_H__
#define __FLYING_CONTROL_PANEL_H__

#include <QWidget>

namespace Ui {
	class FlyingControlPanel;
}

class FlyingControlPanel : public QWidget
{
	Q_OBJECT
public:
	explicit FlyingControlPanel(QWidget *parent = nullptr);
	~FlyingControlPanel();

private slots:

private:
	Ui::FlyingControlPanel* _ui;
};

#endif // __FLYING_CONTROL_PANEL_H__
