#include "patchscalegraphicsitem.h"
#include <QDebug>
#include <QtMath>
#include <QGraphicsScene>

#if (QT_VERSION >= QT_VERSION_CHECK(5,0,0))
#pragma execution_character_set("utf-8")
#endif

patchScaleGraphicsItem::patchScaleGraphicsItem(QGraphicsItem *parent) : QGraphicsItem(parent)
{
}

void patchScaleGraphicsItem::setRectF(QRectF rf)
{
    rectF = rf;
}

QRectF patchScaleGraphicsItem::boundingRect() const
{
    return rectF;
}

#include <QPainter>
void patchScaleGraphicsItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    int starA = 210 * 16;
    int spanA = 120 * 16;
    painter->setPen(QPen(Qt::green, 4,Qt::SolidLine));
    painter->drawArc(rectF, starA, spanA);



    painter->setPen(QPen(Qt::green, 2,Qt::SolidLine));
    for (int angle = 121;angle<240;angle++) {


        QRectF scaleRect1 = zoomRect(rectF, 1.05);
        QRectF scaleRect2 = zoomRect(rectF, 1.1);

        if (angle%30 == 0) {
            painter->drawLine(calcAnglePoint(scaleRect2.center(), scaleRect2.width()/2, angle),
                              calcAnglePoint(rectF.center(), rectF.width()/2, angle));



        }
        else if (angle%10 == 0) {
            painter->drawLine(calcAnglePoint(scaleRect1.center(), scaleRect1.width()/2, angle),
                              calcAnglePoint(rectF.center(), rectF.width()/2, angle));
        }
    }



    QPointF keya = calcAnglePoint(rectF.center(), rectF.width()/2, 180);


    QFont font;
    font.setPointSize(12);
    painter->setFont(font);
    painter->drawText(QRectF(keya.x()-100,keya.y()-50,200,20),  Qt::AlignHCenter, "ºá¹ö:"+anStr);


    painter->drawText(QRectF(keya.x()-100,-keya.y()+30,200,20),  Qt::AlignHCenter, "¸©Ñö:"+paStr);


    //    painter->setPen(QPen(Qt::green, 1,Qt::SolidLine));
//    QPointF keya = calcAnglePoint(rectF.center(), rectF.width()/2, 180);

//    painter->setBrush(Qt::green);
//    painter->drawPolygon(QPolygonF() << keya << keya+QPointF(-qTan(M_PI*30/180)*20,-20) << keya+QPointF(qTan(M_PI*30/180)*20,-20));

//    painter->drawPolygon(QPolygonF() << keya+QPointF(-qTan(M_PI*30/180)*24,-24) << keya+QPointF(qTan(M_PI*30/180)*24,-24) <<
//                         keya+QPointF(qTan(M_PI*30/180)*27,-27) << keya+QPointF(-qTan(M_PI*30/180)*27,-27));


//    QFont font;
//    font.setPointSize(12);
//    painter->setFont(font);
//    painter->drawText(QRectF(keya.x()-100,keya.y()-50,200,20),  Qt::AlignHCenter, "ºá¹ö:0.0");


    //painter->drawText(QRectF(keya.x-100, keya.y-100, 200, 30), QString("nihaoahadohasodasd"));


}

QPointF patchScaleGraphicsItem::calcAnglePoint(QPointF center, qreal radius, qreal angle)
{
    return QPointF(qSin(M_PI * angle / 180)*radius+center.x(), -qCos(M_PI * angle / 180)*radius+center.y());
}

QRectF patchScaleGraphicsItem::zoomRect(QRectF rc, qreal zoom)
{
    return QRectF(rc.center().x()-rc.width()*zoom/2,
             rc.center().y()-rc.height()*zoom/2,
             rc.width()*zoom,
                  rc.height()*zoom);
}

void patchScaleGraphicsItem::setAngle(qreal ang)
{
    if (ang >=0 && ang <180) {
        anStr = QString::number(-ang, 'f', 1);
    }
    else {
        anStr = QString::number(360-ang, 'f', 1);
    }

}

void patchScaleGraphicsItem::setPatch(qreal pat)
{
    paStr = QString::number(-pat, 'f', 1);
}
