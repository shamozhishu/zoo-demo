#ifndef __GROUND_CHECK_PANEL_H__
#define __GROUND_CHECK_PANEL_H__

#include <QWidget>

namespace Ui {
	class GroundCheckPanel;
}

class GroundCheckPanel : public QWidget
{
	Q_OBJECT
public:
	explicit GroundCheckPanel(QWidget *parent = nullptr);
	~GroundCheckPanel();

private slots:

private:
	Ui::GroundCheckPanel* _ui;
};

#endif // __GROUND_CHECK_PANEL_H__
