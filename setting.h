#ifndef SETTING_H
#define SETTING_H

#include <QWidget>
#include <QPainter>
#include <QGraphicsPathItem>
#include <QMediaPlayer>
#include <QMediaPlaylist>

namespace Ui {
class Setting;
}

class Setting : public QWidget
{
    Q_OBJECT

public:
    explicit Setting(QWidget *parent = nullptr);
    void playMusic();
    ~Setting();

private:
    Ui::Setting *ui;
    QMediaPlayer* m_mediaplayer;
    QMediaPlaylist* m_musicList;

signals:
    void show_main_page();

private slots:
    void Show_Setting_Page();
    void on_backBtn_clicked();
    void change_bgm_volume();
    //void change_soundeffect_volume();
    void on_nextBgmBtn_clicked();
    void on_priBgmBtn_clicked();
};

#endif // SETTING_H
