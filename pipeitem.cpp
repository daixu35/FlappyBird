#include "pipeitem.h"
#include <birditem.h>
#include "gamescene.h"
#include <QPointF>
#include <time.h>
PipeItem::PipeItem(qreal score) :
    apipe(new QGraphicsPixmapItem(QPixmap(":/pipe.png"))),pass(0)
{
    //随机生成[-480,-200]的数字，从而随机生成右侧新管道的位置
    ramy=-(200+rand()%(480-200+1));
    apipe->setPos(500,ramy);

    //创造管道水平向左移动动画
    xani = new QPropertyAnimation(this,"x",this);
    xani->setStartValue(480);
    xani->setEndValue(-200);
    xani->setEasingCurve(QEasingCurve::Linear);
    xani->setDuration((9000+1000*score)/(score+3));

    //当动画结束 移除管道
    connect(xani, &QPropertyAnimation::finished, [=](){
        scene()->removeItem(this);
        delete this;
    });

    xani->start();
    addToGroup(apipe);
}

PipeItem::~PipeItem()
{
}

qreal PipeItem::x() const
{
    return m_x;
}

void PipeItem::pipestop()
{
    xani->stop();
}
void PipeItem::pipestart()
{
    xani->start();
}
void PipeItem::pipepause()
{
    xani->pause();
}
void PipeItem::piperesume()
{
    xani->resume();
}
void PipeItem::setX(qreal x)
{
    m_x = x;

    //如果小鸟通过了管道，增加1分
    if(x<0&&!pass){
        pass=1;
        QGraphicsScene* nowscene=scene();
                GameScene* myscene = dynamic_cast<GameScene *>(nowscene);
                if(nowscene){
                    myscene->Scoreadd();
                }
    }

    //如果小鸟撞上了管道，发出碰撞信号
    if(collision()){
        emit collidesignal();
    }
    setPos(x,ramy);
}

//碰撞检测函数
bool PipeItem::collision()
{
    QList<QGraphicsItem*> collidingItems = apipe->collidingItems();
      foreach (QGraphicsItem * item , collidingItems){
          birditem * birdie = dynamic_cast<birditem*>(item);
          if(birdie){
              return true;
          }
      }
      return false;
}
