#include "flappyapp.h"
#include "ui_flappyapp.h"

FlappyApp::FlappyApp(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FlappyApp)
{
    ui->setupUi(this);

    m_movie = new QMovie(":/startsbg.gif");
    m_movie->setScaledSize(size());
    m_label = new QLabel(this);
    m_label->setMovie(m_movie);
    m_movie->setScaledSize(QSize(432, 644));
    m_movie->start();
    m_label->lower();

    ui->playGame->move(141, 350);
    ui->playGame->setFixedSize(150, 50);
    ui->playGame->setStyleSheet("QPushButton {background-color: transparent;} "
                                "QPushButton {color: black; font-size: 48px; font-family: Impact;}"
                                "QPushButton:hover {color: red; font-size: 50px;}");



}

FlappyApp::~FlappyApp()
{
    delete ui;
}

void FlappyApp::on_playGame_clicked()
{
    this->hide();
    emit game_page();
}

void FlappyApp::Show_Main_Page()
{
    this->show();
}

void FlappyApp::on_Option_clicked()
{
    this->hide();
    emit setting_page();
}
