#include "Player.h"
#include <QKeyEvent>
#include <QGraphicsScene>
#include "bullet.h"
#include <QDebug>
#include"enemy.h"
#include <QGraphicsItem>
#include <QAudioOutput>
#include <QtMultimedia/QMediaPlayer>
#include <game.h>
#include "bullet2.h"
#include <QTimer>
extern Game* game ;
Player::Player(QGraphicsItem* parent ):QGraphicsPixmapItem(parent){
    bulletsound = new QMediaPlayer;
    audioOutput = new QAudioOutput;
    bulletsound->setAudioOutput(audioOutput);
    // ...
    bulletsound->setSource(QUrl::fromLocalFile("/Users/hirad2hhk/Downloads/shoot.mp3"));
    audioOutput->setVolume(50);
    setPixmap(QPixmap("/Users/hirad2hhk/Downloads/pixilart-drawing(3).png"));
    QTimer* timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this ,SLOT(checkcollision()));
    timer->start(50);


}
void Player::keyPressEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_Left){
        if(pos().x()>0){
        this->setPos(x()-10,y());
        }
    }
    else if(event->key()==Qt::Key_Right){
        if(pos().x()+100<800){
        this->setPos(x()+10,y());
        }
    }
    else if (event->key()==Qt::Key_Space){
        Bullet * bullet = new Bullet();
        bullet->setPos(x(),y());
        scene()->addItem(bullet);
        if(bulletsound->activeAudioTrack() == 1){
        bulletsound->setPosition(0);
        bulletsound->play();
        }
        else if (bulletsound->activeAudioTrack()==0){
        bulletsound->setPosition(0);
        bulletsound->play();
        }


    }
}
void Player::spawn(){
    Enemy* enemy = new Enemy();
    scene()->addItem(enemy);
}
void Player::checkcollision()
{
    QList<QGraphicsItem*> colliding_Items= collidingItems();
    int n = colliding_Items.size();
    for (int i = 0 ; i < n ; ++i){
        if(typeid(*(colliding_Items[i]))== typeid(Bullet2)){
        if(game->health->getHealth()>1){
            game->health->decrease();



        }
        else if(game->health->getHealth()==1){
            return ;
        }
        }
    }
}

