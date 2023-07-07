#include "flappyapp.h"
#include "ui_flappyapp.h"
#include <QProcess>

FlappyApp::FlappyApp(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FlappyApp)
{
    ui->setupUi(this);

    // 背景动画
    m_movie = new QMovie(":/startsbg.gif");
    m_movie->setScaledSize(size());
    m_label = new QLabel(this);
    m_label->setMovie(m_movie);
    m_movie->setScaledSize(QSize(432, 644));
    m_movie->start();
    m_label->lower();

    // 标题文字设置
    ui->FlappyBird->move(110, 30);
    ui->FlappyBird->setFixedSize(300, 150);
    ui->FlappyBird->setStyleSheet("QLabel {color: rgb(65,105,225); font-size: 48px; font-family: Impact;}");
    ui->subFlappyBird->move(112, 75);
    ui->subFlappyBird->setFixedSize(300, 150);
    ui->subFlappyBird->setStyleSheet("QLabel {color: rgb(65,105,225); font-size: 36px; font-family: 黑体; font-weight: bold;}");

    // 开始游戏的按钮
    ui->playGame->move(141, 350);
    ui->playGame->setFixedSize(150, 50);
    ui->playGame->setStyleSheet("QPushButton {background-color: transparent;}"
                                "QPushButton {color: black; font-size: 48px; font-family: Impact;}"
                                "QPushButton:hover {color: red; font-size: 56px;}");

    // 设置按钮的设置
    ui->Option->move(141, 395);
    ui->Option->setFixedSize(150, 50);
    ui->Option->setStyleSheet("QPushButton {background-color: transparent;}"
                              "QPushButton {color: black; font-size: 32px; font-family: Impact;}"
                              "QPushButton:hover {color: red; font-size: 36px;}");

    // 帮助按钮的设置
    ui->HelpBtn->move(141, 435);
    ui->HelpBtn->setFixedSize(150, 50);
    ui->HelpBtn->setStyleSheet("QPushButton {background-color: transparent;}"
                              "QPushButton {color: black; font-size: 38px; font-family: Impact;}"
                              "QPushButton:hover {color: red; font-size: 46px;}");

    // 退出按钮的设置
    ui->exitBtn->move(141, 475);
    ui->exitBtn->setFixedSize(150, 50);
    ui->exitBtn->setStyleSheet("QPushButton {background-color: transparent;}"
                              "QPushButton {color: black; font-size: 38px; font-family: Impact;}"
                              "QPushButton:hover {color: red; font-size: 46px;}");
}

FlappyApp::~FlappyApp()
{
    delete ui;
    if (m_movie != nullptr) delete m_movie;
    if (m_label != nullptr) delete m_label;
}

void FlappyApp::Show_Main_Page()
{
    this->show();
}

void FlappyApp::on_playGame_clicked()
{
    this->close();
    emit game_page();
}

void FlappyApp::on_Option_clicked()
{
    this->close();
    emit setting_page();
}

void FlappyApp::on_HelpBtn_clicked()
{
    this->close();
    emit help_page();
}

void FlappyApp::on_exitBtn_clicked()
{
    QApplication::quit();
}
