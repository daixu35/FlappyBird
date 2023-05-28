#include "setting.h"
#include "ui_setting.h"

Setting::Setting(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Setting)
{
    ui->setupUi(this);
    m_mediaplayer = new QMediaPlayer(this);

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

    // 设置背景音乐
    m_musicList = new QMediaPlaylist(m_mediaplayer);
    m_musicList->addMedia(QUrl("qrc:/music/default1.mp3"));
    m_musicList->addMedia(QUrl("qrc:/music/default2.mp3"));
    m_musicList->setPlaybackMode(QMediaPlaylist::CurrentItemInLoop);
    m_mediaplayer->setPlaylist(m_musicList);
    m_mediaplayer->setVolume(50);

    // 初始化设置界面的音乐调节界面
    ui->mask->setFixedSize(420, 400);
    ui->mask->move(6, 20);
    ui->mask->setStyleSheet("background-color: rgba(0, 0, 0, 50);border-radius: 10px;");
    ui->mask->lower();
    ui->Volume->setFont(QFont("华文琥珀", 16, QFont::Bold));
    ui->Volume->setFixedSize(150, 50);
    ui->bgmVolume->setFont(QFont("华文隶书", 14, QFont::Bold));
    ui->bgmVolume->setFixedSize(100, 50);
    ui->bgmVolume->move(45, 95);
    ui->SoundEffects->setFont(QFont("华文隶书", 14, QFont::Bold));
    ui->SoundEffects->setFixedSize(100, 50);
    ui->SoundEffects->move(45, 135);
    ui->bgmVolumeSlider->setValue(25);
    ui->bgmVolumeSlider->setStyleSheet("QSlider::handle:horizontal { background-color: blue; }");
    ui->SoundEffectsslider->setValue(25);
    ui->SoundEffectsslider->setStyleSheet("QSlider::handle:horizontal { background-color: blue; }");
    connect(ui->bgmVolumeSlider, &QSlider::valueChanged, this, &Setting::change_bgm_volume);
    //connect(ui->SoundEffectsslider, &QSlider::valueChanged, this, SLOT(change_soundeffect_volume()));

    // 设置音乐自选切换
    ui->musicListName->move(45, 200);
    ui->musicListName->setFont(QFont("华文隶书", 14, QFont::Bold));
    ui->musicListName->setFixedSize(100, 50);
    ui->bgmChangeLabel->move(230, 200);
    ui->bgmChangeLabel->setFont(QFont("华文隶书", 12, QFont::Bold));
    ui->bgmChangeLabel->setFixedSize(100, 50);
    ui->nextBgmBtn->move(322, 212);
    ui->nextBgmBtn->setFixedSize(50, 20);
    ui->nextBgmBtn->setStyleSheet("QPushButton {background-color: transparent;}"
                              "QPushButton {color: black; font-size: 34px; font-family: Impact;}"
                              "QPushButton:hover {color: red; font-size: 46px;}");
    ui->priBgmBtn->move(180, 212);
    ui->priBgmBtn->setFixedSize(50, 20);
    ui->priBgmBtn->setStyleSheet("QPushButton {background-color: transparent;}"
                              "QPushButton {color: black; font-size: 34px; font-family: Impact;}"
                              "QPushButton:hover {color: red; font-size: 46px;}");

    // 切换背景图片

}

Setting::~Setting()
{
    delete ui;
    if (m_mediaplayer != nullptr) delete m_mediaplayer;
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

void Setting::playMusic()
{
    m_mediaplayer->play();
}

void Setting::change_bgm_volume()
{
    int value = ui->bgmVolumeSlider->value();
    m_mediaplayer->setVolume(value);
}

void Setting::on_nextBgmBtn_clicked()
{
    QString bgm = ui->bgmChangeLabel->text();
    if (bgm == "默认音乐1")
        ui->bgmChangeLabel->setText("默认音乐2");
    else
        ui->bgmChangeLabel->setText("默认音乐1");
    m_musicList->setPlaybackMode(QMediaPlaylist::Loop);
    m_mediaplayer->playlist()->next();
    m_musicList->setPlaybackMode(QMediaPlaylist::CurrentItemInLoop);
}

void Setting::on_priBgmBtn_clicked()
{
    QString bgm = ui->bgmChangeLabel->text();
    if (bgm == "默认音乐1")
        ui->bgmChangeLabel->setText("默认音乐2");
    else
        ui->bgmChangeLabel->setText("默认音乐1");
    m_musicList->setPlaybackMode(QMediaPlaylist::Loop);
    m_mediaplayer->playlist()->next();
    m_musicList->setPlaybackMode(QMediaPlaylist::CurrentItemInLoop);
}
