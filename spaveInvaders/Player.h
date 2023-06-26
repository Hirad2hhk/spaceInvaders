#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsRectItem>
#include <QKeyEvent>
#include <QObject>
#include <QMediaPlayer>
#include <QGraphicsPixmapItem>
class Player:public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    void keyPressEvent(QKeyEvent* event);
    Player(QGraphicsItem * parent=0);
    QAudioOutput *audioOutput;

public slots:
    void spawn();
    void checkcollision();
private:
    QMediaPlayer* bulletsound;

};

#endif // PLAYER_H
