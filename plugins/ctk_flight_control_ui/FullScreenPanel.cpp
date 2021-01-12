#include "FullScreenPanel.h"
#include "ui_FullScreenPanel.h"
#include <QFile>

#if (QT_VERSION >= QT_VERSION_CHECK(5,0,0))
#pragma execution_character_set("utf-8")
#endif

FullScreenPanel::FullScreenPanel(QWidget *parent)
	: QWidget(parent)
	, _ui(new Ui::FullScreenPanel)
{
	_ui->setupUi(this);
	setWindowFlags(Qt::FramelessWindowHint);
	connect(_ui->pushButton, &QPushButton::clicked, [this]
	{
		emit quitFullScreen();
	});

	QFile file(":/qss/psblack.css");
	if (file.open(QFile::ReadOnly))
	{
		QString styleSheet = QLatin1String(file.readAll());
		setStyleSheet(styleSheet);
		file.close();
	}
}

FullScreenPanel::~FullScreenPanel()
{
	delete _ui;
}
