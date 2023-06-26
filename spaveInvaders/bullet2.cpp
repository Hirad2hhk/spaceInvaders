#include "bullet2.h"
#include <QTimer>
#include <QGraphicsScene>
#include<enemy.h>
#include"game.h"
#include "block.h"
#include <QGraphicsPixmapItem>
#include "Player.h"
#include "bullet.h"
extern Game* game;
Bullet2::Bullet2()
{
    setPixmap(QPixmap("/Users/hirad2hhk/Downloads/pixilart-drawing(1).png"));
    QTimer* timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this ,SLOT(Move()));
    timer->start(40);

}

void Bullet2::Move()
{
    QList<QGraphicsItem*> colliding_Items= collidingItems();
    int n = colliding_Items.size();
    for(int i = 0; i<n ; ++i){
        if(typeid(*(colliding_Items[i]))== typeid(Player)||typeid(*(colliding_Items[i]))== typeid(Bullet)){

            scene()->removeItem(this);
            delete this;

            return;
        }
        if(typeid(*(colliding_Items[i]))== typeid(Block)){

            scene()->removeItem(this);
            delete this;

            return;
        }
    }
    setPos(x(),y()+6);
    if(pos().y()>600){
        scene()->removeItem(this);
        delete this;
    }
}
