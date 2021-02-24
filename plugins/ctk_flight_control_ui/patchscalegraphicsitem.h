#ifndef PATCHSCALEGRAPHICSITEM_H
#define PATCHSCALEGRAPHICSITEM_H

#include <QGraphicsItem>

class patchScaleGraphicsItem : public QGraphicsItem
{
public:
    explicit patchScaleGraphicsItem(QGraphicsItem *parent = nullptr);


    QRectF rectF = QRectF(-10,-10,20,20);
    void setRectF(QRectF rf);

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    QPointF calcAnglePoint(QPointF center, qreal radius, qreal angle);
    QRectF zoomRect(QRectF rc, qreal zoom);

    void setAngle(qreal ang);
    QString anStr = "0.0";
    void setPatch(qreal pat);
    QString paStr = "0.0";

};

#endif // PATCHSCALEGRAPHICSITEM_H
