#include "setting.h"
#include "ui_setting.h"

Setting::Setting(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Setting)
{
    ui->setupUi(this);

    // 设置背景图片
    QPalette pal = this->palette();
    pal.setBrush(QPalette::Background,QBrush(QPixmap(":/settingbg.jpg")));
    setPalette(pal);

    // 设置回退按钮
    ui->backBtn->move(285, 580);
    ui->backBtn->setFixedSize(150, 50);
    ui->backBtn->setStyleSheet("QPushButton {background-color: transparent;}"
                                "QPushButton {color: black; font-size: 48px; font-family: Impact;}"
                                "QPushButton:hover {color: red; font-size: 56px;}");
}

Setting::~Setting()
{
    delete ui;
}

void Setting::Show_Setting_Page()
{
    this->show();
}

void Setting::on_backBtn_clicked()
{
    this->hide();
    emit show_main_page();
}
