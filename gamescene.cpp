#include "gamescene.h"
#include <QKeyEvent>
#include "birditem.h"
#include "ground.h"
#include "gameover.h"
#include "bonus.h"

GameScene::GameScene(QObject *parent) :
    QGraphicsScene(parent),startsign(0),is_paused(0),gameoverbool(0),score(0)
{
    setpipetimer();
    //水管定时器 用于定时间间隔生成新水管

    // 生成道具
    setbonustimer();
    invincibletimer=new QTimer(this);
    invincibletimer->setSingleShot(true);
    connect(invincibletimer,&QTimer::timeout,[=](){
        invincible=0;
        });

    startImage = new QGraphicsPixmapItem(QPixmap(":/start.png"));
    startImage->setPos(0,0);
    startImage->setZValue(100);
    addItem(startImage);
   //放在最顶层

    gameoverImage = new QGraphicsPixmapItem(QPixmap(":/gameover.png"));
    nankaiImage = new QGraphicsPixmapItem(QPixmap(":/beida.png"));
    show_score = new QGraphicsTextItem(" 分数:0 ");
    show_score->setPos(216, 30);
    show_score->setZValue(20);
    QFont font;
    font.setPointSize(40); //

    // 使用 QFont 对象来更改 QGraphicsTextItem 的字体
    show_score->setFont(font);

    // 使用 QColor 对象来更改 QGraphicsTextItem 的文本颜色
    show_score->setDefaultTextColor(QColor(Qt::white)); // 设置字体颜色为白色
    addItem(show_score);


    ground = new groundItem;
    ground->setZValue(10);
       addItem(ground);
         // 设置Z值为10，放在最上面
}

void GameScene::birddef()
{
    bird = new birditem(QPixmap(":/0.png"));
    addItem(bird);
    bird->setZValue(20);
}

void GameScene::mainstart()
{
    startsign=1;
    removeItem(startImage);
        delete startImage;
    bird->birdstart();
    if(!pipetimer->isActive()){
        pipetimer->start(2000);
    }
    if(!bonustimer->isActive()){
        QTimer::singleShot(1000, [=]() {
            bonustimer->start(2000); // Your QTimer object
        });
    }
}

void GameScene::Scoreadd()
{
    score++;
    show_score->setPlainText("分数:"+QString::number(score));
}

void GameScene::setpipetimer()
{
 pipetimer = new QTimer(this);
 connect(pipetimer,&QTimer::timeout,[=](){
     PipeItem* pipe = new PipeItem(score);
     //如果小鸟与水管碰撞，游戏结束
     connect(pipe,&PipeItem::collidesignal,[=](){
         pipetimer->stop();
         gameover();
     });
     //如果小鸟与地板碰撞，游戏结束
     connect(bird,&birditem::collidesignal2,[=](){
         gameover();
     });
     addItem(pipe);
 });
}

void GameScene::setbonustimer()
{
   bonustimer = new QTimer(this);
   connect(bonustimer,&QTimer::timeout,[=](){
    bool Produce_Bonus=(rand()%(100)>75);
    if(true){
        Bonus* tmp_Bonus=new Bonus(score);
        addItem(tmp_Bonus);
        connect(tmp_Bonus,&Bonus::touchedsignal,[=](){
               invincible=1;
               invincibletimer->start(4000);
               removeItem(tmp_Bonus);
                   delete tmp_Bonus;
        });

       }
   });
}

void GameScene::gameover()
{
    emit(show_gameover_page(score));
    gameoverbool=1; //已结束游戏
    bird->birdstop();   //鸟停止运动
    ground->groundstop();   //地板停止运动
    showscore();

    addItem(gameoverImage);
    gameoverImage->setPos(0,0);
    gameoverImage->setZValue(100);
    addItem(nankaiImage);
    nankaiImage->setPos(138,400);
    nankaiImage->setZValue(100);
    //显示游戏结束和校徽画面

    //将画面内所有水管都停止运动
    QList<QGraphicsItem*> sceneItems = items();
    for(int i=0; i<sceneItems.size(); i++){
        if (i == 0)
        {
            PipeItem* pipe = qgraphicsitem_cast<PipeItem*>(sceneItems[0]);
            if(pipe){
                pipe->pipestop();
            }
        }
        else
        {
            Bonus* tempBonus = qgraphicsitem_cast<Bonus*>(sceneItems[1]);
            if (tempBonus){
                tempBonus->Bonusstop();
            }
        }
    }
    pipetimer->stop();
    bonustimer->stop();
    //停止水管计时器 不再生成新水管
}

void GameScene::showscore()
{
    scoretext = new QGraphicsTextItem();
    QString lastscore="分数:" + QString::number(score);
    scoretext->setHtml(lastscore);

    //设置分数显示界面字体和颜色
    QFont font("Consolas",20,QFont::Bold);
    scoretext->setFont(font);
    QColor color(126,12,110);
    scoretext->setDefaultTextColor(color);

    //设置位置
    addItem(scoretext);
    scoretext->setPos(35 ,280);
}

void GameScene::keyPressEvent(QKeyEvent *event)
{
    if(startsign==0)
        mainstart();
    //第一次空格将移除开始界面图片，并让小鸟，水管开始运动
    if(!gameoverbool)
    {
        if((event->key()==Qt::Key_Space&&!is_paused)||(event->key()==Qt::Key_W&&!is_paused)){
            bird->jump();
    }
    else if(event->key()==Qt::Key_Escape||event->key()==Qt::Key_W){
        if(is_paused==0){
            is_paused=1;
            bird->birdpause();   //鸟停止运动
            ground->groundpause();   //地板停止运动
            QList<QGraphicsItem*> sceneItems = items();
                for(int i=0; i<sceneItems.size(); i++){
                    PipeItem * pipe = qgraphicsitem_cast<PipeItem*>(sceneItems[i]);
                    if(pipe){
                        pipe->pipepause();
                    }
                }
            pipetimer->stop();
        }
        else{
            is_paused=0;
            bird->birdresume();
            ground->groundresume();
            QList<QGraphicsItem*> sceneItems = items();
                for(int i=0; i<sceneItems.size(); i++){
                    PipeItem * pipe = qgraphicsitem_cast<PipeItem*>(sceneItems[i]);
                    if(pipe){
                        pipe->piperesume();
                    }
                }
            pipetimer->start();

    }
}

//若游戏已结束 则空格不再有任何作用
    }
QGraphicsScene::keyPressEvent(event);
}
