#ifndef FLIGHTATTITUDEGRAPHICSVIEW_H
#define FLIGHTATTITUDEGRAPHICSVIEW_H

#include <QGraphicsView>

#include "patchscalegraphicsitem.h"

class QGraphicsRectItem;
class pieGraphicsItem;
class sideslipGraphicsItem;
class airspeedGraphicsItem;
class heightGraphicsItem;
class bottomInfoGraphicsItem;
class flightAttitudeGraphicsView : public QGraphicsView
{
    Q_OBJECT
public:
    explicit flightAttitudeGraphicsView(QWidget *parent = nullptr);

protected:

    virtual void showEvent(QShowEvent *event) override;

private:
    QGraphicsRectItem *itGround = nullptr;
    QGraphicsRectItem *it = nullptr;
    QGraphicsScene *scene = nullptr;

    pieGraphicsItem *pp = nullptr;

    patchScaleGraphicsItem *patchScale = nullptr;
    sideslipGraphicsItem *sid = nullptr;
    airspeedGraphicsItem *sad = nullptr;
    heightGraphicsItem *hei = nullptr;
    bottomInfoGraphicsItem *btm = nullptr;
signals:

    void sigSetPatchingAngle(qreal PA);
    void sigSetRollAngle(qreal RA);
    void sigSetSideslip(qreal SI);
    void sigSetAirspeed(qreal AD);
    void sigSetHeight(qreal HEI);

public slots:
};

#endif // FLIGHTATTITUDEGRAPHICSVIEW_H
