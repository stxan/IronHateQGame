#include "headers/enemy.h"
#include <QTimer>
#include <QBrush>
#include <QGraphicsScene>
#include <stdlib.h>
#include "headers/game.h"

extern Game *game;

Enemy::Enemy() {
    int pos_x = rand() % 700;
    int pos_y = rand() % 500;
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
