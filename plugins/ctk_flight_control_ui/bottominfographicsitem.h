#ifndef BOTTOMINFOGRAPHICSITEM_H
#define BOTTOMINFOGRAPHICSITEM_H

#include <QGraphicsItem>

class bottomInfoGraphicsItem : public QGraphicsItem
{
public:
    bottomInfoGraphicsItem();
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF rectF = QRectF(-10,-10,20,20);
    void setRectF(QRectF rf);
};

#endif // BOTTOMINFOGRAPHICSITEM_H
