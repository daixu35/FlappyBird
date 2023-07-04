#ifndef BONUS_H
#define BONUS_H

#include <QDebug>
#include <QGraphicsScene>
#include <QGraphicsItemGroup>
#include <QGraphicsPixmapItem>
#include <QPropertyAnimation>

class Bonus : public QObject , public QGraphicsItemGroup
{
    Q_OBJECT
    Q_PROPERTY(qreal x READ x WRITE setX)
public:
    explicit Bonus(qreal score);
    ~Bonus();
    qreal x() const;
    void Bonusstop();
    void Bonusstart();
    void Bonuspause();
    void Bonusresume();
signals:
    void touchedsignal();
public slots:
    void setX(qreal x);
private slots:

private:
    bool touched();
    QGraphicsPixmapItem* bonus;
    QPropertyAnimation* xani;
    qreal m_x;
    qreal y;
};

#endif // BONUS_H
