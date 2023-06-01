#include "gameover.h"
#include "ui_gameover.h"
#include <QProcess>

Gameover::Gameover(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Gameover)
{
    ui->setupUi(this);
}

Gameover::~Gameover()
{
    delete ui;
}

void::Gameover::Show_Gameover_Page(int& score){
    this->show();
    ui->score->setText("Your Score:"+QString::number(score));
    ui->score->adjustSize();
    ui->score->setAlignment(Qt::AlignVCenter);
}

//重新开始（还没搞出来）
void Gameover::on_restart_clicked()
{
    emit restartButton();
    this->close();
}

//回到主菜单
void Gameover::on_mainmenu_clicked()
{
    emit mainmenu();
    this->close();
}

//结束程序
void Gameover::on_exit_clicked()
{
    QCoreApplication::exit(0);
}
