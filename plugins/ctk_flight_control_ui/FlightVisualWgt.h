#ifndef __FLIGHT_VISUAL_WGT_H__
#define __FLIGHT_VISUAL_WGT_H__

#include <QtWidgets/QWidget>

class RenderThread;
class CmdRegThread;
class FlightVisualWgt : public QWidget
{
	Q_OBJECT
public:
	FlightVisualWgt(QString renderAdaName, QStringList cmdset, QString datadir = "", QWidget* parent = Q_NULLPTR);
	~FlightVisualWgt();
	void resgisterCmdset(QStringList cmdset);
	bool isCmdRegCompleted() const;

signals:
	void cmdRegistered();

private:
	RenderThread* _renderThread;
	CmdRegThread* _cmdRegThread;
};

#endif // __FLIGHT_VISUAL_WGT_H__
