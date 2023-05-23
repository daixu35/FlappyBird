#include "help.h"
#include "ui_help.h"

Help::Help(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Help)
{
    ui->setupUi(this);

    QPalette pal = this->palette();
    pal.setBrush(QPalette::Background,QBrush(QPixmap(":/helpbg.jpg")));
    setPalette(pal);

    ui->backBtn->move(285, 580);
    ui->backBtn->setFixedSize(150, 50);
    ui->backBtn->setStyleSheet("QPushButton {background-color: transparent;}"
                                "QPushButton {color: black; font-size: 48px; font-family: Impact;}"
                                "QPushButton:hover {color: red; font-size: 56px;}");
}

Help::~Help()
{
    delete ui;
}

void Help::Show_Help_Page()
{
    this->show();
}

void Help::on_backBtn_clicked()
{
    this->hide();
    emit show_main_page();
}
