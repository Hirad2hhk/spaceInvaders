#include "block.h"
#include <QGraphicsPixmapItem>
#include <bullet.h>
#include <QGraphicsScene>
#include "bullet.h"
#include <QTimer>
#include"game.h"
#include "bullet2.h"

extern Game* game;
#include <QTimer>
Block::Block(): QGraphicsPixmapItem()
{
    setPixmap(QPixmap("/Users/hirad2hhk/Downloads/pixilart-drawing(4).png"));
    health =new Health;
    QTimer* timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this ,SLOT(checkcollision()));
    timer->start(50);


}

void Block::checkcollision()
{
    QList<QGraphicsItem*> colliding_Items= collidingItems();
    int n = colliding_Items.size();
    for (int i = 0 ; i < n ; ++i){
        if(typeid(*(colliding_Items[i]))== typeid(Bullet)||typeid(*(colliding_Items[i]))== typeid(Bullet2)){
            if(this->health->getHealth()>1){
                this->health->decrease();


                if(this->health->getHealth()==1){
                    this->setPixmap(QPixmap("/Users/hirad2hhk/Downloads/pixil-frame-0.png"));
                }

            }
            else if(this->health->getHealth()==1){
                scene()->removeItem(this);
                delete this;


                return;
            }
        }
    }
}
