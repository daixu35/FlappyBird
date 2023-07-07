/********************************************************************************
** Form generated from reading UI file 'help.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HELP_H
#define UI_HELP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Help
{
public:
    QPushButton *backBtn;
    QLabel *playEdu;
    QTextBrowser *eduText;
    QLabel *mask;

    void setupUi(QWidget *Help)
    {
        if (Help->objectName().isEmpty())
            Help->setObjectName(QStringLiteral("Help"));
        Help->resize(400, 641);
        backBtn = new QPushButton(Help);
        backBtn->setObjectName(QStringLiteral("backBtn"));
        backBtn->setGeometry(QRect(280, 550, 93, 28));
        playEdu = new QLabel(Help);
        playEdu->setObjectName(QStringLiteral("playEdu"));
        playEdu->setGeometry(QRect(40, 70, 72, 15));
        eduText = new QTextBrowser(Help);
        eduText->setObjectName(QStringLiteral("eduText"));
        eduText->setGeometry(QRect(60, 110, 256, 192));
        mask = new QLabel(Help);
        mask->setObjectName(QStringLiteral("mask"));
        mask->setGeometry(QRect(140, 350, 72, 15));

        retranslateUi(Help);

        QMetaObject::connectSlotsByName(Help);
    } // setupUi

    void retranslateUi(QWidget *Help)
    {
        Help->setWindowTitle(QApplication::translate("Help", "Form", nullptr));
        backBtn->setText(QApplication::translate("Help", "Back", nullptr));
        playEdu->setText(QApplication::translate("Help", "\347\216\251\346\263\225:", nullptr));
        eduText->setHtml(QApplication::translate("Help", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt; font-weight:600;\">1.\347\202\271\345\207\273play\345\215\263\345\217\257\345\274\200\345\247\213\346\270\270\346\210\217\357\274\214\345\210\232\350\277\233\345\216\273\346\227\266\346\230\257\346\232\202\345\201\234\347\212\266\346\200\201\357\274\214\345\275\223\347\216\251\345\256\266\345\207\206\345\244\207\345\245\275\345\220\216\357\274\214\345\215\225\346\234\272\344\270\200\344\270\213\347\252\227\345\217\243\357\274\214\345\217\226\346\266\210\351\230\262\350\257\257\345\274\200\357\274\214\346\216\245\347\235\200\347\233\264"
                        "\346\216\245\346\214\211\344\270\213\347\251\272\346\240\274\345\215\263\345\217\257\345\274\200\345\247\213\346\270\270\347\216\251\343\200\202\347\242\260\345\210\260\347\256\241\351\201\223\351\232\234\347\242\215\347\211\251\345\215\263\346\270\270\346\210\217\347\273\223\346\235\237\357\274\214\345\220\203\345\210\260\347\272\242\350\211\262\350\221\241\350\220\204\351\201\223\345\205\267\345\220\216\345\217\257\344\273\245\346\227\240\346\225\214\344\270\200\346\256\265\346\227\266\351\227\264\343\200\202\347\202\271\345\207\273\347\225\214\351\235\242\345\217\263\344\270\213\350\247\222Back\351\200\200\345\233\236\345\210\260\344\270\273\347\225\214\351\235\242\343\200\202</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:14pt; font-weight:600;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span "
                        "style=\" font-size:14pt; font-weight:600;\">2.\347\202\271\345\207\273Option\350\277\233\345\205\245\350\256\276\347\275\256\347\225\214\351\235\242\357\274\214\345\217\257\344\273\245\350\260\203\346\225\264\346\270\270\346\210\217\347\232\204\350\203\214\346\231\257\351\237\263\344\271\220\343\200\202</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:14pt; font-weight:600;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt; font-weight:600;\">3.\347\202\271\345\207\273Exit\351\200\200\345\207\272\346\270\270\346\210\217\343\200\202</span></p></body></html>", nullptr));
        mask->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Help: public Ui_Help {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HELP_H
