#ifndef SETTING_H
#define SETTING_H

#include <QWidget>
#include <QPainter>
#include <QGraphicsPathItem>

namespace Ui {
class Setting;
}

class Setting : public QWidget
{
    Q_OBJECT

public:
    explicit Setting(QWidget *parent = nullptr);
    ~Setting();

private:
    Ui::Setting *ui;

signals:
    void show_main_page();

private slots:
    void Show_Setting_Page();
    void on_backBtn_clicked();
};

#endif // SETTING_H
