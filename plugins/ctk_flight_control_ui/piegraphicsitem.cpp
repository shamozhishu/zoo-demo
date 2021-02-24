#include "piegraphicsitem.h"
#include <QPainter>
#include <QtMath>
#include <QDebug>

#if (QT_VERSION >= QT_VERSION_CHECK(5,0,0))
#pragma execution_character_set("utf-8")
#endif

pieGraphicsItem::pieGraphicsItem()
{

}

QRectF pieGraphicsItem::boundingRect() const
{
    return rectF;
}

void pieGraphicsItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(QPen(Qt::green, 1,Qt::SolidLine));
    QPointF keya = calcAnglePoint(rectF.center(), rectF.width()/2, 180);

    painter->setBrush(Qt::green);
    painter->drawPolygon(QPolygonF() << keya << keya+QPointF(-qTan(M_PI*30/180)*20,-20) << keya+QPointF(qTan(M_PI*30/180)*20,-20));

    painter->drawPolygon(QPolygonF() << keya+QPointF(-qTan(M_PI*30/180)*24,-24) << keya+QPointF(qTan(M_PI*30/180)*24,-24) <<
                         keya+QPointF(qTan(M_PI*30/180)*27,-27) << keya+QPointF(-qTan(M_PI*30/180)*27,-27));

    painter->setPen(QPen(Qt::green, 4,Qt::SolidLine));

    qreal kes =  (rectF.height()-70*2)/12;
    kc = kes;

    for (int i=0;i<=12;i++){
        if (i == 2 || i == 10) {
            painter->drawLine(-35,-kes*6+kes*i,35,-kes*6+kes*i);

            QFont font;
            font.setPointSize(12);
            painter->setFont(font);

            if (i == 2) {

                painter->drawText(QRectF(-70,-kes*6+kes*i-10, 30, 20),  Qt::AlignRight, "20");
                painter->drawText(QRectF(40,-kes*6+kes*i-10, 30, 20),  Qt::AlignLeft, "20");

            }
            else {
                painter->drawText(QRectF(-70,-kes*6+kes*i-10, 30, 20),  Qt::AlignRight, "-20");
                painter->drawText(QRectF(40,-kes*6+kes*i-10, 30, 20),  Qt::AlignLeft, "-20");
            }
        }
        else
            painter->drawLine(-15,-kes*6+kes*i,15,-kes*6+kes*i);
    }
}

void pieGraphicsItem::setRectF(QRectF rf)
{
    rectF = rf;
}

QPointF pieGraphicsItem::calcAnglePoint(QPointF center, qreal radius, qreal angle)
{
    return QPointF(qSin(M_PI * angle / 180)*radius+center.x(), -qCos(M_PI * angle / 180)*radius+center.y());

}
