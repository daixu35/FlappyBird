#include "game.h"
#include "ui_game.h"
#include <QGraphicsPixmapItem>

Game::Game(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Game)
{
    ui->setupUi(this);
    initGameScene();

    // 设置回退按钮
    ui->EscButton->setText("Back");
    ui->EscButton->move(285, 580);
    ui->EscButton->setFixedSize(150, 50);
    ui->EscButton->setStyleSheet("QPushButton {background-color: transparent;}"
                                "QPushButton {color: black; font-size: 48px; font-family: Impact;}"
                                "QPushButton:hover {color: red; font-size: 56px;}");

}

Game::~Game()
{
    delete ui;
}

void Game::Show_Game_Page()
{
    initGameScene();
    this->show();
    setFocus();
}

void Game::on_EscButton_clicked()
{
    this->close();
    emit show_main_page();
}

void Game::initGameScene()
{
    scene = new GameScene(this);

    // 初始化场景
    scene->setSceneRect(0, 0, 432, 644);
    QGraphicsPixmapItem* pixItem = new QGraphicsPixmapItem(QPixmap(":/bg.png"));
    scene->addItem(pixItem);
    pixItem->setPos(QPointF(0, 0));

    scene->birddef();

    ui->Box->setScene(scene);
}

