#ifndef AIRSPEEDGRAPHICSITEM_H
#define AIRSPEEDGRAPHICSITEM_H

#include <QGraphicsItem>


class airspeedGraphicsItem: public QGraphicsItem
{
public:
    airspeedGraphicsItem();

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    QRectF rectF = QRectF(-10,-10,20,20);
    void setRectF(QRectF rf);


    void setairspeed(qreal sirS);
    qreal airspeed = 0;
};

#endif // AIRSPEEDGRAPHICSITEM_H
