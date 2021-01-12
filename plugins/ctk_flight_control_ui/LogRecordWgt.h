#ifndef __LOG_RECORD_WGT_H__
#define __LOG_RECORD_WGT_H__

#include <QWidget>

namespace Ui {
	class LogRecordWgt;
}

class LogRecordWgt : public QWidget
{
	Q_OBJECT
public:
	explicit LogRecordWgt(QWidget *parent = nullptr);
	~LogRecordWgt();
	void setTableHeader(QString keyName, QString ValName);
	void setTitle(QString title, QColor clr = QColor(255, 255, 0));
	void addLog(const QStringList &txt, QColor txtColor = QColor(255, 255, 255), bool bDebug = false, int txtAlignment = Qt::AlignCenter);

private slots:

private:
	void checkClear();
	void clearTable(bool all = false);

private:
	int _recordCount;
	int _logShowMaxNum;
	Ui::LogRecordWgt* _ui;
};

#endif // __LOG_RECORD_WGT_H__
