/********************************************************************************
** Form generated from reading UI file 'setting.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTING_H
#define UI_SETTING_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Setting
{
public:
    QPushButton *backBtn;
    QLabel *Volume;
    QLabel *bgmVolume;
    QSlider *bgmVolumeSlider;
    QLabel *mask;
    QLabel *musicListName;
    QLabel *bgmChangeLabel;
    QPushButton *nextBgmBtn;
    QPushButton *priBgmBtn;
    QCheckBox *musicSwitch;

    void setupUi(QWidget *Setting)
    {
        if (Setting->objectName().isEmpty())
            Setting->setObjectName(QStringLiteral("Setting"));
        Setting->resize(680, 626);
        backBtn = new QPushButton(Setting);
        backBtn->setObjectName(QStringLiteral("backBtn"));
        backBtn->setGeometry(QRect(260, 540, 93, 28));
        Volume = new QLabel(Setting);
        Volume->setObjectName(QStringLiteral("Volume"));
        Volume->setGeometry(QRect(20, 40, 72, 31));
        bgmVolume = new QLabel(Setting);
        bgmVolume->setObjectName(QStringLiteral("bgmVolume"));
        bgmVolume->setGeometry(QRect(40, 110, 81, 21));
        bgmVolumeSlider = new QSlider(Setting);
        bgmVolumeSlider->setObjectName(QStringLiteral("bgmVolumeSlider"));
        bgmVolumeSlider->setGeometry(QRect(170, 110, 241, 22));
        bgmVolumeSlider->setMaximum(100);
        bgmVolumeSlider->setOrientation(Qt::Horizontal);
        bgmVolumeSlider->setTickPosition(QSlider::NoTicks);
        mask = new QLabel(Setting);
        mask->setObjectName(QStringLiteral("mask"));
        mask->setGeometry(QRect(40, 310, 541, 301));
        musicListName = new QLabel(Setting);
        musicListName->setObjectName(QStringLiteral("musicListName"));
        musicListName->setGeometry(QRect(40, 190, 81, 31));
        bgmChangeLabel = new QLabel(Setting);
        bgmChangeLabel->setObjectName(QStringLiteral("bgmChangeLabel"));
        bgmChangeLabel->setGeometry(QRect(260, 200, 161, 31));
        nextBgmBtn = new QPushButton(Setting);
        nextBgmBtn->setObjectName(QStringLiteral("nextBgmBtn"));
        nextBgmBtn->setGeometry(QRect(390, 200, 93, 28));
        priBgmBtn = new QPushButton(Setting);
        priBgmBtn->setObjectName(QStringLiteral("priBgmBtn"));
        priBgmBtn->setGeometry(QRect(140, 200, 93, 28));
        musicSwitch = new QCheckBox(Setting);
        musicSwitch->setObjectName(QStringLiteral("musicSwitch"));
        musicSwitch->setGeometry(QRect(40, 270, 161, 19));

        retranslateUi(Setting);

        QMetaObject::connectSlotsByName(Setting);
    } // setupUi

    void retranslateUi(QWidget *Setting)
    {
        Setting->setWindowTitle(QApplication::translate("Setting", "Form", nullptr));
        backBtn->setText(QApplication::translate("Setting", "Back", nullptr));
        Volume->setText(QApplication::translate("Setting", "\345\243\260\351\237\263\350\256\276\347\275\256\357\274\232", nullptr));
        bgmVolume->setText(QApplication::translate("Setting", "\350\203\214\346\231\257\351\237\263\344\271\220:", nullptr));
        mask->setText(QString());
        musicListName->setText(QApplication::translate("Setting", "\351\237\263      \344\271\220", nullptr));
        bgmChangeLabel->setText(QApplication::translate("Setting", "\351\273\230\350\256\244\351\237\263\344\271\2201", nullptr));
        nextBgmBtn->setText(QApplication::translate("Setting", ">", nullptr));
        priBgmBtn->setText(QApplication::translate("Setting", "<", nullptr));
        musicSwitch->setText(QApplication::translate("Setting", "\346\232\202\345\201\234\346\222\255\346\224\276\351\237\263\344\271\220", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Setting: public Ui_Setting {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTING_H
