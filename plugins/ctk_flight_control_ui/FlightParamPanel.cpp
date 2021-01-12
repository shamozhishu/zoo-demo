#include "FlightParamPanel.h"
#include "ui_FlightParamPanel.h"
#include "UIActivator.h"

#if (QT_VERSION >= QT_VERSION_CHECK(5,0,0))
#pragma execution_character_set("utf-8")
#endif

FlightParamPanel::FlightParamPanel(QWidget *parent)
	: QWidget(parent)
	, _ui(new Ui::FlightParamPanel)
{
	_ui->setupUi(this);
	_ui->tableWidget->setItemDelegate(new NoFocusDelegate());

	QStringList paramlist_cols[4];
	paramlist_cols[0] << "工作模式" << "控制模式" << "飞行状态" << "姿态源" << "空速源" << "地速源" << "导航源";
	paramlist_cols[1] << "仿真模式" << "程控模式" << "待飞" << "仿真源" << "空速" << "仿真源" << "仿真源";
	paramlist_cols[2] << "爬升率指令" << "航向指令" << "滚转指令" << "空速指令" << "油门指令" << "高度指令" << "目标航点";
	paramlist_cols[3] << "0.00m/s" << "235.00" << "0.00" << "360.00km/s" << "0%" << "1155.00m" << "0";

	for (int row = 0; row < 7; row++)
	{
		for (int col = 0; col < 4; col++)
		{
			QTableWidgetItem* pItem = new QTableWidgetItem(paramlist_cols[col][row]);
			_ui->tableWidget->setItem(row, col, pItem);
			pItem->setFlags(pItem->flags() & (~Qt::ItemIsEditable));
			if (col % 2 != 0)
			{
				pItem->setTextColor(QColor(0, 255, 255));
				pItem->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
			}
			else
			{
				pItem->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter);
			}
		}
	}
}

FlightParamPanel::~FlightParamPanel()
{
	delete _ui;
}
