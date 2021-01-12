#include "StatusCheckPanel.h"
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include "ui_StatusCheckPanel.h"
#include "UIActivator.h"

#if (QT_VERSION >= QT_VERSION_CHECK(5,0,0))
#pragma execution_character_set("utf-8")
#endif

StatusCheckPanel::StatusCheckPanel(QWidget *parent)
	: QWidget(parent)
	, _ui(new Ui::StatusCheckPanel)
{
	_ui->setupUi(this);

	QStringList btnNames[2];
	btnNames[0] << "链路状态检查" << "设备通讯状态" << "数据存储" << "惯导正常对准" << "读取全参" << "关键参数确定"
		<< "舵面检查" << "左副翼" << "左V尾" << "升降舵" << "数据链检查";
	btnNames[1] << "空速管检查" << "风标系统检查" << "姿态及定位" << "发动机检查" << "假开车" << "冷运转"
		<< "开车" << "右副翼" << "右V尾" << "发动机发电" << "完成地检";

	int idx = 0;
	QGridLayout* pLayout = new QGridLayout;
	_ui->frame->setLayout(pLayout);
	for (int col = 0; col < 4; col++)
	{
		for (int row = 0; row < 11; row++)
		{
			QWidget* pWgt;
			if (col % 2 == 0)
			{
				QPushButton* pBtn = new QPushButton(btnNames[idx][row]);
				pWgt = pBtn;
			}
			else
			{
				QLabel* pLbl = new QLabel;
				pLbl->setAlignment(Qt::AlignCenter);
				QPixmap pmap;
				if (col == 3)
					pmap.load(":/images/Resources/images/warning.png");
				else
					pmap.load(":/images/Resources/images/normal.png");
				pLbl->setPixmap(pmap);
				pWgt = pLbl;
			}

			pLayout->addWidget(pWgt, row, col, Qt::AlignCenter);
		}

		if (idx == 0)
			idx++;
	}
}

StatusCheckPanel::~StatusCheckPanel()
{
	delete _ui;
}
