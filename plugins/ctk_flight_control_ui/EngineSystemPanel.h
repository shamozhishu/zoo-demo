#ifndef __ENGINE_SYSTEM_PANEL_H__
#define __ENGINE_SYSTEM_PANEL_H__

#include <QWidget>

namespace Ui {
	class EngineSystemPanel;
}

class EngineSystemPanel : public QWidget
{
	Q_OBJECT
public:
	explicit EngineSystemPanel(QWidget *parent = nullptr);
	~EngineSystemPanel();

private slots:

private:
	Ui::EngineSystemPanel* _ui;
};

#endif // __ENGINE_SYSTEM_PANEL_H__
