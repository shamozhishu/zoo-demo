#include "flightattitudegraphicsview.h"
#include <QGraphicsRectItem>
#include <QPropertyAnimation>
#include <QScrollBar>
#include <QtMath>
#include <QDebug>
#include "piegraphicsitem.h"
#include "sideslipgraphicsitem.h"
#include <QtMath>
#include "airspeedgraphicsitem.h"
#include "heightgraphicsitem.h"
#include "bottominfographicsitem.h"

#if (QT_VERSION >= QT_VERSION_CHECK(5,0,0))
#pragma execution_character_set("utf-8")
#endif

flightAttitudeGraphicsView::flightAttitudeGraphicsView(QWidget *parent) : QGraphicsView(parent)
{

    scene = new QGraphicsScene(this);
    scene->setItemIndexMethod(QGraphicsScene::NoIndex);
    scene->setSceneRect(-150, -200, 300, 400);
    setScene(scene);
    setCacheMode(CacheBackground);
    setViewportUpdateMode(BoundingRectViewportUpdate);
    setRenderHint(QPainter::Antialiasing);
    setTransformationAnchor(AnchorUnderMouse);
    scale(qreal(0.8), qreal(0.8));
    //setMinimumSize(400, 400);
    setWindowTitle(tr("Elastic Nodes"));
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);




    //qDebug() << this->width() << this->height();

    it = new QGraphicsRectItem();
    it->setPen(QPen(Qt::white,0));
    it->setBrush(QColor(0,163,232));
    it->setZValue(0.1);

    itGround = new QGraphicsRectItem();
    itGround->setPen(QPen(Qt::white,0));
    itGround->setBrush(QColor(167,103,68));
    itGround->setZValue(0);

    pp = new pieGraphicsItem();
    pp->setZValue(1);

    sid = new sideslipGraphicsItem();
    sid->setZValue(2);



    sad = new airspeedGraphicsItem();
    sad->setZValue(2);

    //QGraphicsEllipseItem *itEll = new QGraphicsEllipseItem(QRect(-50,-50,100,100));
    scene->addItem(it);
    scene->addItem(itGround);
    scene->addItem(pp);
    scene->addItem(sid);
    scene->addItem(sad);


    patchScale = new patchScaleGraphicsItem();
    patchScale->setZValue(2);
    scene->addItem(patchScale);




    hei = new heightGraphicsItem();
    hei->setZValue(2);
    scene->addItem(hei);


     btm = new bottomInfoGraphicsItem();
     btm->setZValue(2);
     scene->addItem(btm);



    static qreal aPA = 0;
    static qreal aRA = 0;

    connect(this, &flightAttitudeGraphicsView::sigSetPatchingAngle,[=](qreal PA){
        PA = PA * pp->kc/5;
        aPA = PA;
        it->setX(-aPA*qSin(M_PI*aRA/180));
        it->setY(aPA*qCos(M_PI*aRA/180));
        patchScale->setPatch(PA/pp->kc*5);
        scene->update();
    });

    connect(this, &flightAttitudeGraphicsView::sigSetRollAngle, [=](qreal RA){
        aRA = RA;
        it->setRotation(RA);
        pp->setRotation(RA);
        patchScale->setAngle(RA);
        it->setX(-aPA*qSin(M_PI*RA/180));
        it->setY(aPA*qCos(M_PI*RA/180));
    });

    connect(this, &flightAttitudeGraphicsView::sigSetSideslip, [=](qreal si){
        sid->setSideslip(si);
        scene->update();
    });

    connect(this, &flightAttitudeGraphicsView::sigSetAirspeed, [=](qreal asd){
        sad->setairspeed(asd);
        scene->update();
    });

    connect(this, &flightAttitudeGraphicsView::sigSetHeight, [=](qreal hi){
        hei->setHeight(hi);
        scene->update();
    });
}

void flightAttitudeGraphicsView::showEvent(QShowEvent *event)
{
    if (scene != nullptr)
        scene->setSceneRect(-width()/2,-height()/2, width(),height());
    if (it != nullptr) {
        int r = static_cast<int>(qSqrt(width()*width()+height()*height())*2.5);
        it->setRect(-r/2,-r,r,r);
    }

    if (patchScale != nullptr)
        patchScale->setRectF(QRectF(-height()/2,-height()/2,height(),height()));


    if (itGround != nullptr)
        itGround->setRect(-width(),-height(), width()*2,height()*2);

    if (pp != nullptr)
        pp->setRectF(QRectF(-height()/2,-height()/2,height(),height()));

    if (sid != nullptr)
        sid->setRectF(QRectF(-height()/2,-height()/0.8/2,height(),height()/6));

    if (sad != nullptr)
        sad->setRectF(QRectF(-width()/0.8/2,-height()/0.8/2,width()/0.8-height()/0.8,height()/0.8));

    if (hei != nullptr)
        hei->setRectF(QRectF(width()/0.8/2-(width()/0.8-height()/0.8),-height()/0.8/2,width()/0.8-height()/0.8,height()/0.8));

    if (btm != nullptr)
        btm->setRectF(QRectF(-height()/2,height()/0.8/2-height()/6,height(),height()/6));


}
