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
	btnNames[0] << "��·״̬���" << "�豸ͨѶ״̬" << "���ݴ洢" << "�ߵ�������׼" << "��ȡȫ��" << "�ؼ�����ȷ��"
		<< "������" << "����" << "��Vβ" << "������" << "���������";
	btnNames[1] << "���ٹܼ��" << "���ϵͳ���" << "��̬����λ" << "���������" << "�ٿ���" << "����ת"
		<< "����" << "�Ҹ���" << "��Vβ" << "����������" << "��ɵؼ�";

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
