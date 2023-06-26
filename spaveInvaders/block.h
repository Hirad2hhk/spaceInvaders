#ifndef BLOCK_H
#define BLOCK_H
#include <health.h>
#include <QGraphicsPixmapItem>
#include <QObject>
class Block:public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Block();
public slots:
    void checkcollision();
private:
    Health* health;


};

#endif // BLOCK_H
