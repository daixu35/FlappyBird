/********************************************************************************
** Form generated from reading UI file 'game.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAME_H
#define UI_GAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Game
{
public:
    QPushButton *EscButton;
    QGraphicsView *Box;

    void setupUi(QWidget *Game)
    {
        if (Game->objectName().isEmpty())
            Game->setObjectName(QStringLiteral("Game"));
        Game->resize(434, 646);
        Game->setMinimumSize(QSize(0, 0));
        Game->setMaximumSize(QSize(16777215, 16777215));
        Box = new QGraphicsView(Game);
        Box->setObjectName(QStringLiteral("Box"));
        Box->setGeometry(QRect(0, 0, 434, 646));
        Box->setFixedSize(QSize(434, 646));
        EscButton = new QPushButton(Game);
        EscButton->setObjectName(QStringLiteral("EscButton"));
        EscButton->setGeometry(QRect(10, 0, 93, 28));

        retranslateUi(Game);

        QMetaObject::connectSlotsByName(Game);
    } // setupUi

    void retranslateUi(QWidget *Game)
    {
        Game->setWindowTitle(QApplication::translate("Game", "Form", nullptr));
        EscButton->setText(QApplication::translate("Game", "Esc", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Game: public Ui_Game {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAME_H
