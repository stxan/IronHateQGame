#include "points.h"
#include <QTimer>
#include <QBrush>
#include <QGraphicsScene>
#include <stdlib.h>
#include "game.h"

extern Game *game;

Points::Points() {
    int rand_x = rand() % 700;
    int rand_y = rand() % 500;
    setPos(rand_x, rand_y);
    setRect(0, 0, 30, 30);
    setBrush(QBrush(Qt::green, Qt::SolidPattern));

    points_spawn_sound = new QMediaPlayer();
    points_spawn_sound->setMedia(QUrl("qrc:/sounds/spawn.mp3"));
    points_spawn_sound->play();

}


