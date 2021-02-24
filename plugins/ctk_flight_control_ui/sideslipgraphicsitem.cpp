#include "sideslipgraphicsitem.h"
#include <QFont>
#include <QPainter>
#include <QDebug>
#include <QtMath>

#if (QT_VERSION >= QT_VERSION_CHECK(5,0,0))
#pragma execution_character_set("utf-8")
#endif

sideslipGraphicsItem::sideslipGraphicsItem()
{

}

QRectF sideslipGraphicsItem::boundingRect() const
{
    return rectF;
}

void sideslipGraphicsItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    QFont font;
    font.setPointSize(12);
    painter->setFont(font);
    //painter->setBrush(Qt::red);
    //painter->drawRect(rectF);


    qreal kes =  rectF.width()/10;

    qreal sid = sia*kes/10;
    qreal sidVL = sid;


    painter->setBrush(QColor(100,100,100));
    painter->setPen(QPen(Qt::green, 1,Qt::SolidLine));
    QPointF keya = rectF.center();
    painter->drawPolygon(QPolygonF() << keya << keya+QPointF(-qTan(M_PI*30/180)*20,-20) << keya+QPointF(qTan(M_PI*30/180)*20,-20));

    painter->setPen(QPen(Qt::green, 4,Qt::SolidLine));

    painter->drawLine(rectF.center().x()-rectF.width()/2,rectF.center().y(),
                      rectF.center().x()+rectF.width()/2,rectF.center().y());

    qreal offset = 15;
    int iDVL = 0;
    while(sidVL<=(rectF.center().x()+rectF.width()/2-offset)) {
        if (sidVL>=(rectF.center().x()-rectF.width()/2+offset)) {
            if (iDVL%2!=0) {
                painter->drawLine(sidVL,rectF.center().y(),sidVL,rectF.center().y()+10);
                painter->drawText(QRectF(sidVL-20,rectF.center().y()+15,40,20),  Qt::AlignHCenter, QString::number(-(int)((sidVL-sid)/kes)*10));

            }
            else
                painter->drawLine(sidVL,rectF.center().y(),sidVL,rectF.center().y()+20);
        }
        iDVL++;
        sidVL += kes;
    }

    qreal sidVR = sid;
    int iDVR = 0;
    while(sidVR>=(rectF.center().x()-rectF.width()/2+offset)) {
        if (sidVR<=(rectF.center().x()+rectF.width()/2-offset)){
            if (iDVR%2!=0) {
                painter->drawLine(sidVR,rectF.center().y(),sidVR,rectF.center().y()+10);
                painter->drawText(QRectF(sidVR-20,rectF.center().y()+15,40,20),  Qt::AlignHCenter, QString::number(-(int)((sidVR-sid)/kes)*10));

            }
            else {
                painter->drawLine(sidVR,rectF.center().y(),sidVR,rectF.center().y()+20);


            }
        }
        iDVR++;
        sidVR -= kes;
    }

	painter->drawText(QRectF(keya.x() - 100, keya.y() - 40, 200, 20), Qt::AlignHCenter, "²à»¬½Ç " + QString::number(sia, 'f', 1));


}

void sideslipGraphicsItem::setRectF(QRectF rf)
{
    rectF = rf;
}

void sideslipGraphicsItem::setSideslip(qreal SIA)
{
    sia = SIA;
    qDebug()<< sia;
}
