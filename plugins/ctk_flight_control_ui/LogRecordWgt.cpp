#include "LogRecordWgt.h"
#include "ui_LogRecordWgt.h"
#include <QDebug>
#include "UIActivator.h"

LogRecordWgt::LogRecordWgt(QWidget *parent)
	: QWidget(parent)
	, _ui(new Ui::LogRecordWgt)
	, _recordCount(0)
	, _logShowMaxNum(100) // 显示的最大行数
{
	_ui->setupUi(this);
	_ui->label->setVisible(false);
	_ui->label_count->setVisible(false);
	_ui->tableWidget->setItemDelegate(new NoFocusDelegate);
}

LogRecordWgt::~LogRecordWgt()
{
	delete _ui;
}

void LogRecordWgt::setTableHeader(QString keyName, QString ValName)
{
	QStringList header;
	header << keyName << ValName;
	_ui->tableWidget->setHorizontalHeaderLabels(header);
}

void LogRecordWgt::setTitle(QString title, QColor clr /*= QColor(255, 255, 0)*/)
{
	if (title == "")
	{
		_ui->label->setVisible(false);
		_ui->label_count->setVisible(false);
	}
	else
	{
		_ui->label->setText(title);
		QString clrStyle = QString("color: rgb(%1, %2, %3);").arg(clr.red()).arg(clr.green()).arg(clr.blue());
		_ui->label_count->setStyleSheet(clrStyle);
		_ui->label->setVisible(true);
		_ui->label_count->setVisible(true);
	}
}

void LogRecordWgt::addLog(const QStringList &txt, QColor txtColor /*= QColor(255, 255, 255)*/, bool bDebug /*= false*/, int txtAlignment /*= Qt::AlignCenter*/)
{
	checkClear();

	QTableWidgetItem *itemKey = new QTableWidgetItem(txt[0]);
	itemKey->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter);
	itemKey->setForeground(QBrush(txtColor));

	QTableWidgetItem *itemTxt = new QTableWidgetItem(txt[1]);
	itemTxt->setTextAlignment(txtAlignment);
	itemTxt->setForeground(QBrush(txtColor));

	int nCnt = _ui->tableWidget->rowCount();
	_ui->tableWidget->setRowCount(nCnt + 1);
	_ui->tableWidget->setItem(nCnt, 0, itemKey);
	_ui->tableWidget->setItem(nCnt, 1, itemTxt);
	_ui->tableWidget->scrollToBottom();

	_recordCount++;
	_ui->label_count->setText(QString("%1").arg(_recordCount));
	if (bDebug)
		qDebug() << txt;
}

void LogRecordWgt::checkClear()
{
	int nCnt = _ui->tableWidget->rowCount();
	if (nCnt >= _logShowMaxNum)
	{
		clearTable();
	}
}

void LogRecordWgt::clearTable(bool all /*= false*/)
{
	if (all)
	{
		_ui->tableWidget->clearContents(); // 清除信息
		_ui->tableWidget->setRowCount(0); // 置零
	}
	else
	{
		int nCnt = _ui->tableWidget->rowCount();
		_recordCount -= nCnt;
		for (int i = 0; i < nCnt - 10; i++)
		{
			_ui->tableWidget->removeRow(i);
		}
	}
}
