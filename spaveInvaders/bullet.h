#ifndef BULLET_H
#define BULLET_H
#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsPixmapItem>
class Bullet:public QObject ,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Bullet();
public slots:
    void Move();
};

#endif // BULLET_H
