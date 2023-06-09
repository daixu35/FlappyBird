#include "ground.h"
#include "birditem.h"
#include <QPixmap>
#include <QTimer>
#include <QPropertyAnimation>

    groundItem::groundItem(QObject *parent) : QObject(parent),
        QGraphicsPixmapItem(QPixmap(":/ground.png"))
    {
        setPos(0, 500);
        //生成地面向左移动的动画
        groundani = new QPropertyAnimation(this, "groundx", this);
        groundani->setStartValue(0);
        groundani->setEndValue(-100);
        groundani->setDuration(1000);
        groundani->setLoopCount(-1);
        groundani->start();

    }

    qreal groundItem::groundx() const
    {
        return m_groundx;
    }


    void groundItem::setgroundx(qreal groundx)
    {
        m_groundx = groundx;
        setPos(groundx, y());
    }

    void groundItem::groundstop()
    {
        groundani->stop();
    }
    void groundItem::groundstart()
    {
        groundani->start();
    }
    void groundItem::groundresume()
    {
        groundani->resume();
    }
    void groundItem::groundpause()
    {
        groundani->pause();
    }

