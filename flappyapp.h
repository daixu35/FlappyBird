#ifndef FLAPPYAPP_H
#define FLAPPYAPP_H

#include <QWidget>

namespace Ui {
class FlappyApp;
}

class FlappyApp : public QWidget
{
    Q_OBJECT

public:
    explicit FlappyApp(QWidget *parent = nullptr);
    ~FlappyApp();

private:
    Ui::FlappyApp *ui;

signals:
    void game_page();
    void setting_page();

private slots:
    void Show_Main_Page();
    void on_playGame_clicked();
    void on_Option_clicked();
};

#endif // FLAPPYAPP_H
