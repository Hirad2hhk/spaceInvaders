 #include "enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <stdlib.h>
#include <QDebug>
#include"game.h"
#include "bullet2.h"
extern Game* game;
Enemy::Enemy():QObject(),QGraphicsPixmapItem()
{
    int randnum = rand()%300;
    this->setPos(0,randnum);
    this->direction = right;
    setPixmap(QPixmap("/Users/hirad2hhk/Downloads/pixilart-drawing(2).png"));
    QTimer* timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this ,SLOT(Move()));
    timer->start(50);
    QTimer* shoottimer = new QTimer();
    connect(shoottimer,SIGNAL(timeout()),this,SLOT(shoot()));
    shoottimer->start(1000);

}

void Enemy::Move()
{
    if (this->direction==right){
        setPos(x()+5,y());
        if(pos().x()==800){
            this->direction=left;
        }
    }
    if (this->direction==left){
        setPos(x()-5,y());
        if(pos().x()==0){
            this->direction=right;
        }
    }
}

void Enemy::shoot(){
    Bullet2* bull = new Bullet2();
    bull->setPos(this->x(),this->y());
    scene()->addItem(bull);
}
