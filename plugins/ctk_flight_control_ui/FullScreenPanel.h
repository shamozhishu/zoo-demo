#ifndef __FULL_SCREEN_PANEL_H__
#define __FULL_SCREEN_PANEL_H__

#include <QWidget>

namespace Ui {
	class FullScreenPanel;
}

class FullScreenPanel : public QWidget
{
	Q_OBJECT
public:
	explicit FullScreenPanel(QWidget *parent = nullptr);
	~FullScreenPanel();

signals:
	void quitFullScreen();

public:
	Ui::FullScreenPanel* _ui;

};

#endif // __FULL_SCREEN_PANEL_H__
