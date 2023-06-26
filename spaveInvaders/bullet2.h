#ifndef BULLET2_H
#define BULLET2_H


#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsPixmapItem>
class Bullet2:public QObject ,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Bullet2();
public slots:
    void Move();
};

#endif // BULLET2_H
