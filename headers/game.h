#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "player.h"
#include "health.h"
#include "score.h"

class Game: public QGraphicsView{
public:
    Game(QWidget * parent=0);
    //void stop();
    QGraphicsScene * scene;
    Player * player;
    Score * score;
    Health * health;

};

#endif // GAME_H
