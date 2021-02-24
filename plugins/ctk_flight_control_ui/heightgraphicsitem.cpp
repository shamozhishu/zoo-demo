#include "heightgraphicsitem.h"
#include <QPainter>
#include <QDebug>

#if (QT_VERSION >= QT_VERSION_CHECK(5,0,0))
#pragma execution_character_set("utf-8")
#endif

heightGraphicsItem::heightGraphicsItem()
{

}

QRectF heightGraphicsItem::boundingRect() const
{
    return rectF;
}

void heightGraphicsItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QFont font;
    font.setPointSize(12);
    painter->setFont(font);
    painter->setPen(QPen(QColor(100,100,100,128), 1,Qt::SolidLine));
    painter->setBrush(QColor(100,100,100,128));
    painter->drawRect(rectF);


    painter->setPen(QPen(Qt::green, 4,Qt::SolidLine));
    qreal kes =  rectF.height()/32;


    qreal sad = hei*kes/5;
    qreal sadVT = sad;

    qreal offset = 15;
    int iVT = 0;
    while(sadVT<=(rectF.center().y()+rectF.height()/2-offset)) {
        if (sadVT>=(rectF.center().y()-rectF.height()/2+offset)) {
            if (iVT%25!=0) {
                painter->drawLine(rectF.left()+15,sadVT,rectF.left()+2,sadVT);
                //painter->drawText(QRectF(sadVT-20,rectF.center().y()+15,40,20),  Qt::AlignHCenter, QString::number((int)((sidVL-sid)/kes)*10));

            }
            else{
                painter->drawLine(rectF.left()+30,sadVT,rectF.left()+2,sadVT);
                if (sadVT<rectF.center().y()-30 || sadVT > rectF.center().y()+30)
                    painter->drawText(QRectF(rectF.left()+32,sadVT-10,rectF.width(),20),  Qt::AlignLeft, QString::number(-iVT));

            }

        }
        iVT += 5;
        sadVT += kes;
    }


    qreal sadVR = sad;

    int iVR = 0;
    while(sadVR>=(rectF.center().y()-rectF.height()/2+offset)) {

        if (sadVR<=(rectF.center().y()+rectF.height()/2-offset)){
            if (iVR%25!=0) {
                painter->drawLine(rectF.left()+15,sadVR,rectF.left()+2,sadVR);
            }
            else {
                painter->drawLine(rectF.left()+30,sadVR,rectF.left()+2,sadVR);


                if (sadVR<rectF.center().y()-30 || sadVR > rectF.center().y()+30)

                    painter->drawText(QRectF(rectF.left()+32,sadVR-10,rectF.width(),20),  Qt::AlignLeft, QString::number(iVR));




            }
        }
        iVR += 5;
        sadVR -= kes;
    }

    painter->setPen(QPen(QColor(20,20,20,160), 1,Qt::SolidLine));
    painter->setBrush(QColor(20,20,20,160));
    painter->drawRect(QRectF(rectF.right()-(rectF.width()-30),rectF.center().y()-20,rectF.width()-30,40));

    painter->setPen(QPen(Qt::green, 4,Qt::SolidLine));
    painter->drawText(QRectF(rectF.right()-(rectF.width()-30),rectF.center().y()-20,rectF.width()-30,40),  Qt::AlignHCenter, "º£°Î¸ß¶È\n"+QString::number(hei,'f', 1));

}

void heightGraphicsItem::setRectF(QRectF rf)
{
    rectF = rf;

}

void heightGraphicsItem::setHeight(qreal HEI)
{
    hei = HEI;
}
