#ifndef FLAPPYAPP_H
#define FLAPPYAPP_H

#include <QWidget>
#include <QMovie>
#include <QLabel>

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
    QMovie* m_movie;
    QLabel* m_label;

signals:
    void game_page();
    void setting_page();
    void help_page();

private slots:
    void Show_Main_Page();
    void on_playGame_clicked();
    void on_Option_clicked();
    void on_HelpBtn_clicked();
    void on_exitBtn_clicked();
};

#endif // FLAPPYAPP_H
