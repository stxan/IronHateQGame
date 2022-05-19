#include "bullet.h"
#include "enemy.h"
#include <QTimer>
#include <QBrush>
#include <QGraphicsScene>
#include <QList>
#include "game.h"
#include <QDebug>

extern Game *game;

enum direction {
  UP, DOWN, LEFT, RIGHT
};

Bullet::Bullet() {
    setRect(13, 0, 10, 10);
    setBrush(QBrush(Qt::yellow, Qt::SolidPattern));
    QTimer *timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(50);
}

Bullet::Bullet(int direction) {
    this->direction = direction;
    setRect(13, 0, 10, 10);
    setBrush(QBrush(Qt::yellow, Qt::SolidPattern));
    QTimer *timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(50);
}

void Bullet::move() {
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; i++) {
        if (typeid(*(colliding_items[i])) == typeid(Enemy)) {
            game->score->increase();
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            delete colliding_items[i];
            delete this;
            return;
        }
    }
    if (direction == UP) {
        setPos(x(), y() - 10);
       // qDebug() << "shoot up";
    }
    else if (direction == DOWN) {
        setPos(x(), y() + 10);
    }
    else if (direction == LEFT) {
        setPos(x() - 10, y());
    }
    else if (direction == RIGHT) {
        setPos(x() + 10, y());
    }
   /* if (pos().y() + rect().height() < 0 || pos().y() - rect().height() > 600 || pos().x() + rect().width() < 0
            || pos().x() - rect().width() > 800) {
        scene()->removeItem(this);
        delete this;
    }*/
}
