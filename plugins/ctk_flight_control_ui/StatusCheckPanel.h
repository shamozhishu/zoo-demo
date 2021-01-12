#ifndef __STATUS_CHECK_PANEL_H__
#define __STATUS_CHECK_PANEL_H__

#include <QWidget>

namespace Ui {
	class StatusCheckPanel;
}

class StatusCheckPanel : public QWidget
{
	Q_OBJECT
public:
	explicit StatusCheckPanel(QWidget *parent = nullptr);
	~StatusCheckPanel();

private slots:

private:
	Ui::StatusCheckPanel* _ui;
};

#endif // __STATUS_CHECK_PANEL_H__
