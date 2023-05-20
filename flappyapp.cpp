#include "flappyapp.h"
#include "ui_flappyapp.h"

FlappyApp::FlappyApp(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FlappyApp)
{
    ui->setupUi(this);
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
