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

    ui->mask->setFixedSize(400, 510);
    ui->mask->move(15, 50);
    ui->mask->setStyleSheet("background-color: rgba(0, 0, 0, 50);border-radius: 10px;");
    ui->mask->lower();

    ui->playEdu->setFont(QFont("华文隶书", 28, QFont::Bold));
    ui->playEdu->setStyleSheet("color:white;");
    ui->playEdu->setFixedSize(100, 50);
    ui->playEdu->move(25, 75);

    ui->eduText->move(50, 150);
    ui->eduText->resize(300, 450);
    ui->eduText->setStyleSheet("background:transparent;border-width:0;border-style:outset;"
                               "color:white;font-size:48px;");


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
