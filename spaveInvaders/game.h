#ifndef GAME_H
#define GAME_H

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <Player.h>
#include "score.h"
#include "health.h"
#include <block.h>
#include <QAudioOutput>
#include <QMediaPlayer>
class Game: public QGraphicsView
{
public:
public:
    Game(QWidget * parent=0);

    QGraphicsScene * scene;
    Player * player;
    Score *score;
    Health* health;
    QMediaPlayer* background;
    QAudioOutput* audioOutput;
    Block* block;
    Block* block1;
    Block* block2;
    Block* block3;
    Block* block4;
};

#endif // GAME_H
