#ifndef __FLIGHT_VISUAL_WGT_H__
#define __FLIGHT_VISUAL_WGT_H__

#include <QtWidgets/QWidget>
#include <ctk_service/Win32Service.h>

class RenderThread;
class CmdRegThread;
class FlightVisualWgt : public QWidget, public Win32Service
{
	Q_OBJECT
	Q_INTERFACES(Win32Service)
public:
	FlightVisualWgt(QString renderAdaName, QStringList cmdset, QString datadir = "", QWidget* parent = Q_NULLPTR);
	~FlightVisualWgt();
	HWND getWnd();
	bool isFocus();
	void resgisterCmdset(QStringList cmdset);
	bool isCmdRegCompleted() const;

signals:
	void cmdRegistered();

private:
	RenderThread* _renderThread;
	CmdRegThread* _cmdRegThread;
};

#endif // __FLIGHT_VISUAL_WGT_H__
