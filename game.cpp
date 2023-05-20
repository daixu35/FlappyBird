#include "game.h"
#include "ui_game.h"
#include <QGraphicsPixmapItem>

Game::Game(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Game)
{
    ui->setupUi(this);
    scene = new GameScene(this);

    // 初始化场景
    scene->setSceneRect(0, 0, 432, 644);
    QGraphicsPixmapItem* pixItem = new QGraphicsPixmapItem(QPixmap(":/bg.png"));
    scene->addItem(pixItem);
    pixItem->setPos(QPointF(0, 0));

    ui->Box->setScene(scene);
}

Game::~Game()
{
    delete ui;
}

void Game::Show_Game_Page()
{
    this->show();
}
