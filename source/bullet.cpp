#include "headers/bullet.h"
#include "headers/enemy.h"
#include <QTimer>
#include <QBrush>
#include <QGraphicsScene>
#include <QList>
#include "headers/game.h"
#include <QDebug>

#define MOVE_OFFSET 10
#define TIMER_PACE 50
#define BULLET_SPAWN_X 13
#define BULLET_SPAWN_Y 0
#define BULLET_WIDTH 10
#define BULLET_HEIGHT 10


extern Game *game;

enum direction {
  UP, DOWN, LEFT, RIGHT
};

Bullet::Bullet() {
    setRect(BULLET_SPAWN_X, BULLET_SPAWN_Y, BULLET_WIDTH, BULLET_HEIGHT);
    setBrush(QBrush(Qt::yellow, Qt::SolidPattern));
    QTimer *timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(TIMER_PACE);
}

Bullet::Bullet(int direction) {
    this->direction = direction;
    setRect(BULLET_SPAWN_X, BULLET_SPAWN_Y, BULLET_WIDTH, BULLET_HEIGHT);
    setBrush(QBrush(Qt::yellow, Qt::SolidPattern));
    QTimer *timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(TIMER_PACE);
}

void Bullet::move() {
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; i++) {
        if (dynamic_cast<Enemy *>(colliding_items[i])) {
            game->score->increase();
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            delete colliding_items[i];
            delete this;
            return;
        }
    }
    if (direction == UP) {
        setPos(x(), y() - MOVE_OFFSET);
    }
    else if (direction == DOWN) {
        setPos(x(), y() + MOVE_OFFSET);
    }
    else if (direction == LEFT) {
        setPos(x() - MOVE_OFFSET, y());
    }
    else if (direction == RIGHT) {
        setPos(x() + MOVE_OFFSET, y());
    }
   /* if (pos().y() + rect().height() < 0 || pos().y() - rect().height() > 600 || pos().x() + rect().width() < 0
            || pos().x() - rect().width() > 800) {
        scene()->removeItem(this);
        delete this;
    }*/
}
