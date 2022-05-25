#include "headers/points.h"
#include <QTimer>
#include <QBrush>
#include <QGraphicsScene>
#include <stdlib.h>
#include "headers/game.h"

#define POINTS_RAND_INIT_X 700
#define POINTS_RAND_INIT_Y 500
#define POINTS_SPAWN_OFFSET_X 0
#define POINTS_SPAWN_OFFSET_Y 0
#define POINTS_SIZE_W 30
#define POINTS_SIZE_H 30

extern Game *game;

Points::Points() {
    int rand_x = rand() % POINTS_RAND_INIT_X;
    int rand_y = rand() % POINTS_RAND_INIT_Y;
    setPos(rand_x, rand_y);
    setRect(POINTS_SPAWN_OFFSET_X, POINTS_RAND_INIT_Y, POINTS_SIZE_W, POINTS_SIZE_H);
    setBrush(QBrush(Qt::green, Qt::SolidPattern));

    points_spawn_sound = new QMediaPlayer();
    points_spawn_sound->setMedia(QUrl("qrc://sounds/mp3/spawn.mp3"));
    points_spawn_sound->play();

}


