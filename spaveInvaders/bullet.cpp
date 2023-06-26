 #include "bullet.h"
#include <QTimer>
#include <QGraphicsScene>
#include<enemy.h>
#include"game.h"
#include "block.h"
#include "bullet2.h"
#include <QGraphicsPixmapItem>
extern Game* game;
Bullet::Bullet()
{
    setPixmap(QPixmap("/Users/hirad2hhk/Downloads/pixilart-drawing(1).png"));
    QTimer* timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this ,SLOT(Move()));
    timer->start(40);

}

void Bullet::Move()
{
    QList<QGraphicsItem*> colliding_Items= collidingItems();
    int n = colliding_Items.size();
    for(int i = 0; i<n ; ++i){
        if(typeid(*(colliding_Items[i]))== typeid(Enemy)){
            game->score->increase();
            scene()->removeItem(colliding_Items[i]);
            scene()->removeItem(this);
            delete colliding_Items[i];
            delete this;

            return;
        }
        if(typeid(*(colliding_Items[i]))== typeid(Block)||typeid(*(colliding_Items[i]))== typeid(Bullet2)){

            scene()->removeItem(this);
            delete this;

            return;
        }
    }
    setPos(x(),y()-10);
    if(pos().y()<0){
        scene()->removeItem(this);
        delete this;
    }
}
