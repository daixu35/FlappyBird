/********************************************************************************
** Form generated from reading UI file 'gameover.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEOVER_H
#define UI_GAMEOVER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Gameover
{
public:
    QLabel *score;
    QPushButton *restart;
    QPushButton *mainmenu;
    QPushButton *exit;
    QLabel *gameoverlabel;

    void setupUi(QWidget *Gameover)
    {
        if (Gameover->objectName().isEmpty())
            Gameover->setObjectName(QStringLiteral("Gameover"));
        Gameover->resize(400, 500);
        score = new QLabel(Gameover);
        score->setObjectName(QStringLiteral("score"));
        score->setGeometry(QRect(100, 170, 281, 41));
        QFont font;
        font.setFamily(QStringLiteral("Cascadia Code SemiBold"));
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        score->setFont(font);
        score->setAlignment(Qt::AlignCenter);
        score->setWordWrap(true);
        restart = new QPushButton(Gameover);
        restart->setObjectName(QStringLiteral("restart"));
        restart->setGeometry(QRect(110, 240, 191, 41));
        restart->setFont(font);
        mainmenu = new QPushButton(Gameover);
        mainmenu->setObjectName(QStringLiteral("mainmenu"));
        mainmenu->setGeometry(QRect(110, 300, 191, 41));
        mainmenu->setFont(font);
        exit = new QPushButton(Gameover);
        exit->setObjectName(QStringLiteral("exit"));
        exit->setGeometry(QRect(110, 360, 191, 41));
        QFont font1;
        font1.setFamily(QStringLiteral("Cascadia Mono SemiBold"));
        font1.setPointSize(14);
        font1.setBold(true);
        font1.setWeight(75);
        exit->setFont(font1);
        gameoverlabel = new QLabel(Gameover);
        gameoverlabel->setObjectName(QStringLiteral("gameoverlabel"));
        gameoverlabel->setGeometry(QRect(-10, -80, 431, 231));
        gameoverlabel->setStyleSheet(QStringLiteral("background-image: url(:/gameover.png);"));

        retranslateUi(Gameover);

        QMetaObject::connectSlotsByName(Gameover);
    } // setupUi

    void retranslateUi(QWidget *Gameover)
    {
        Gameover->setWindowTitle(QApplication::translate("Gameover", "Form", nullptr));
        score->setText(QApplication::translate("Gameover", "Your Score:", nullptr));
        restart->setText(QApplication::translate("Gameover", "Restart", nullptr));
        mainmenu->setText(QApplication::translate("Gameover", "Main Menu", nullptr));
        exit->setText(QApplication::translate("Gameover", "Exit", nullptr));
        gameoverlabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Gameover: public Ui_Gameover {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEOVER_H
