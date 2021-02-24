#ifndef PIEGRAPHICSITEM_H
#define PIEGRAPHICSITEM_H

#include <QGraphicsItem>

class pieGraphicsItem : public QGraphicsItem
{
public:
    pieGraphicsItem();

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    QRectF rectF = QRectF(-10,-10,20,20);
    void setRectF(QRectF rf);

    QPointF calcAnglePoint(QPointF center, qreal radius, qreal angle);


    qreal kc = 1;

};

#endif // PIEGRAPHICSITEM_H
