#include "game.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include "enemy.h"
#include "score.h"
#include "health.h"

#include <QMediaPlayer>
Game::Game(QWidget *parent)
{

    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600); // make the scene 800x600 instead of infinity by infinity (default)

    // make the newly created scene the scene to visualize (since Game is a QGraphicsView Widget,
    // it can be used to visualize scenes)
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);

    // create the player
    player = new Player();
    player->setPos(400,550);

    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    // add the player to the scene
    scene->addItem(player);
    //score
    score = new Score();
    scene->addItem(score);
    //health
    health = new Health();
    health->setPos(health->x(),health->y()+15);
    scene->addItem(health);


    block = new Block;
    block1 = new Block;
    block2 = new Block;
    block3 = new Block;
    block4 = new Block;

    block ->setPos(0,350);
    scene->addItem(block);
    block1 ->setPos(170,350);
    scene->addItem(block1);
    block2 ->setPos(340,350);
    scene->addItem(block2);
    block3 ->setPos(510,350);
    scene->addItem(block3);
    block4 ->setPos(680,350);
    scene->addItem(block4);

    // spawn enemies

    QTimer * timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),player,SLOT(spawn()));
    timer->start(2500);
    background = new QMediaPlayer;
    audioOutput = new QAudioOutput;
    background->setAudioOutput(audioOutput);
    // ...
    background->setSource(QUrl::fromLocalFile("/Users/hirad2hhk/spaveInvaders/bg1.mp3"));
    audioOutput->setVolume(20);
    background->play();
    show();
}
