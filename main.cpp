#include "flappyapp.h"
#include "game.h"
#include "setting.h"
#include "help.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FlappyApp mainPage;
    Game gamePage;
    Setting settingPage;
    Help helpPage;

    mainPage.setWindowTitle("FlappyBird");
    mainPage.setFixedSize(434, 646);
    gamePage.setWindowTitle("FlappyBird-Play");
    gamePage.setFixedSize(434, 646);
    settingPage.setWindowTitle("FlappyBird-Setting");
    settingPage.setFixedSize(434, 646);
    helpPage.setWindowTitle("Flappy-Help");
    helpPage.setFixedSize(434, 646);

    mainPage.show();

    QObject::connect(&mainPage, SIGNAL(game_page()), &gamePage, SLOT(Show_Game_Page()));
    QObject::connect(&mainPage, SIGNAL(setting_page()), &settingPage, SLOT(Show_Setting_Page()));
    QObject::connect(&mainPage, SIGNAL(help_page()), &helpPage, SLOT(Show_Help_Page()));
    QObject::connect(&settingPage, SIGNAL(show_main_page()), &mainPage, SLOT(Show_Main_Page()));
    QObject::connect(&helpPage, SIGNAL(show_main_page()), &mainPage, SLOT(Show_Main_Page()));

    return a.exec();
}
