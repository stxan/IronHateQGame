#include "headers/enemy.h"
#include <QTimer>
#include <QBrush>
#include <QGraphicsScene>
#include <stdlib.h>
#include "headers/game.h"

extern Game *game;

#define RAND_INIT_X 700
#define RAND_INIT_Y 500

Enemy::Enemy() {
    int pos_x = rand() % RAND_INIT_X;
    int pos_y = rand() % RAND_INIT_Y;
    setPixmap(QPixmap("://pictures/png/enemy.png"));
    setPos(pos_x, pos_y);
    QTimer *timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(700);
}

void Enemy::move() {
    int rand_x = rand() % 5;
    int rand_y = rand() % 5;
    setPos(x() + rand_x, y() + rand_y);
}
