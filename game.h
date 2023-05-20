#ifndef GAME_H
#define GAME_H

#include "gamescene.h"
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

signals:
    void show_main_page();

private slots:
    void Show_Game_Page();
};

#endif // GAME_H
