#include "bonus.h"
#include "birditem.h"

Bonus::Bonus(qreal score):bonus(new QGraphicsPixmapItem(QPixmap(":/bonus.png"))){
    y=200+rand()%(201);
    bonus->setPos(500,y);
    xani = new QPropertyAnimation(this,"x",this);
    xani->setStartValue(500);
    xani->setEndValue(-200);
    xani->setEasingCurve(QEasingCurve::Linear);
    xani->setDuration((9000+1000*score)/(score+3));
    connect(xani, &QPropertyAnimation::finished, [=](){
        scene()->removeItem(this);
        delete this;
    });

    xani->start();
    addToGroup(bonus);
}
Bonus::~Bonus(){
}
void Bonus::Bonusstop(){
    xani->stop();
};
void Bonus::Bonusstart(){
    xani->start();
}
void Bonus::Bonuspause(){
    xani->pause();
}
void Bonus::Bonusresume(){
    xani->resume();
}
bool Bonus::touched()
{
    QList<QGraphicsItem*> collidingItems = bonus->collidingItems();
      foreach (QGraphicsItem * item , collidingItems){
          birditem * birdie = dynamic_cast<birditem*>(item);
          if(birdie){
              return true;
          }
      }
      return false;
}
qreal Bonus::x() const{
    return m_x;
}
void Bonus::setX(qreal x)
{
   //如果小鸟吃到了Bonus
    m_x=x;
    if(touched()){
        emit touchedsignal();
    }
    setPos(x,y);

}
