#ifndef __MAIN_VIEW_PANEL_H__
#define __MAIN_VIEW_PANEL_H__

#include <QWidget>

namespace Ui {
	class MainViewPanel;
}

class MainViewPanel : public QWidget
{
	Q_OBJECT
public:
	explicit MainViewPanel(QWidget *parent = nullptr);
	~MainViewPanel();

private slots:

private:
	Ui::MainViewPanel* _ui;
};

#endif // __MAIN_VIEW_PANEL_H__
