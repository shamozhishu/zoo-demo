#include "bottominfographicsitem.h"
#include <QFont>
#include <QPainter>
#include <QDebug>
#include <QtMath>

#if (QT_VERSION >= QT_VERSION_CHECK(5,0,0))
#pragma execution_character_set("utf-8")
#endif

bottomInfoGraphicsItem::bottomInfoGraphicsItem()
{

}

QRectF bottomInfoGraphicsItem::boundingRect() const
{
    return rectF;
}

void bottomInfoGraphicsItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{


    QFont font;
    font.setPointSize(12);
    painter->setFont(font);
    //painter->setBrush(Qt::red);
    //painter->drawRect(rectF);


    qreal kes =  rectF.width()/10;

    qreal sid = 0*kes/10;
    qreal sidVL = sid;


    painter->setBrush(QColor(100,100,100));
    painter->setPen(QPen(Qt::green, 1,Qt::SolidLine));


    //painter->drawRect(rectF);
    painter->drawText(QRectF(rectF.left(),rectF.bottom()-30,120,20),  Qt::AlignHCenter, "航向:0.0");
    painter->drawText(QRectF(rectF.right()-180,rectF.bottom()-30,180,20),  Qt::AlignHCenter, "起飞点高度:0.0");

}

void bottomInfoGraphicsItem::setRectF(QRectF rf)
{
    rectF = rf;

}
