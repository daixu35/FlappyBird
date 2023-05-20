#include "flappyapp.h"
#include "game.h"
#include "setting.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FlappyApp mainPage;
    Game gamePage;
    Setting settingPage;

    mainPage.setWindowTitle("FlappyBird");
    mainPage.setFixedSize(434, 646);
    gamePage.setWindowTitle("FlappyBird-Play");
    gamePage.setFixedSize(434, 646);
    settingPage.setWindowTitle("FlappyBird-Setting");
    settingPage.setFixedSize(434, 646);

    mainPage.show();

    QObject::connect(&mainPage, SIGNAL(game_page()), &gamePage, SLOT(Show_Game_Page()));
    QObject::connect(&mainPage, SIGNAL(setting_page()), &settingPage, SLOT(Show_Setting_Page()));

    int x = 20;

    return a.exec();
}
