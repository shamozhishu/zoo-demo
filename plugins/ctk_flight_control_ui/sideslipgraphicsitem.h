#ifndef SIDESLIPGRAPHICSITEM_H
#define SIDESLIPGRAPHICSITEM_H


#include <QGraphicsItem>

class sideslipGraphicsItem : public QGraphicsItem
{
public:
    sideslipGraphicsItem();


    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF rectF = QRectF(-10,-10,20,20);
    void setRectF(QRectF rf);
    void setSideslip(qreal SIA);

    qreal sia = 0;

};

#endif // SIDESLIPGRAPHICSITEM_H
