#ifndef HEIGHTGRAPHICSITEM_H
#define HEIGHTGRAPHICSITEM_H

#include <QGraphicsItem>


class heightGraphicsItem: public QGraphicsItem
{
public:
    heightGraphicsItem();
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    QRectF rectF = QRectF(-10,-10,20,20);
    void setRectF(QRectF rf);

    void setHeight(qreal HEI);
    qreal hei = 0;

};

#endif // HEIGHTGRAPHICSITEM_H
