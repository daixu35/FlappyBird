#ifndef GAME_H
#define GAME_H

#include "gamescene.h"
#include "gameover.h"
#include <QWidget>

namespace Ui {
class Game;
}

class Game : public QWidget
{
    Q_OBJECT

public:
    explicit Game(QWidget *parent = nullptr);
    ~Game();

private:
    Ui::Game *ui;
    GameScene* scene;
    Gameover* gameoverPage;

signals:
    void show_main_page();
    void show_gameover_page();
    void restart();

private slots:
    void Show_Game_Page();
    void Restart();
    void Mainmenu();
};

#endif // GAME_H
