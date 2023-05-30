#ifndef SCENE_H
#define SCENE_H

#include <QDebug>
#include <QTimer>
#include <QGraphicsScene>
#include <birditem.h>
#include "pipeitem.h"
#include "ground.h"
#include <QGraphicsPixmapItem>

class GameScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit GameScene(QObject *parent = nullptr);
    void birddef();
    void mainstart();
    void Scoreadd();

signals:

private:
    void setpipetimer();
    QTimer* pipetimer;
    birditem* bird;
    QGraphicsPixmapItem* startImage;
    QGraphicsPixmapItem* gameoverImage;
    QGraphicsPixmapItem* nankaiImage;
    QGraphicsTextItem* show_score;
    bool startsign;
    bool is_paused;
    void gameover();
    groundItem* ground;
    bool gameoverbool;
    int score;
    QGraphicsTextItem* scoretext;
    void showscore();

public slots:

    // QGraphicsScene interface
protected:
    void keyPressEvent(QKeyEvent *event);
};

#endif // SCENE_H
