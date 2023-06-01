#ifndef GAMEOVER_H
#define GAMEOVER_H

#include <QWidget>
#include <gamescene.h>

namespace Ui {
class Gameover;
}

class GameScene;
class Gameover : public QWidget
{
    Q_OBJECT

public:
    explicit Gameover(QWidget *parent = nullptr);
    ~Gameover();

signals:
    void return_main_page();
    void restartButton();
    void mainmenu();
private slots:
    void Show_Gameover_Page(int &);

    void on_restart_clicked();

    void on_mainmenu_clicked();

    void on_exit_clicked();

private:
    Ui::Gameover *ui;
};

#endif // GAMEOVER_H
