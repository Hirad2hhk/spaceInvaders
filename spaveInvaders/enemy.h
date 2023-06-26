#ifndef ENEMY_H
#define ENEMY_H
#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsPixmapItem>
class Enemy:public QObject ,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    enum Direction { right, left};
    Direction direction;
    Enemy();
public slots:
    void Move();
    void shoot();
};

#endif // ENEMY_H
