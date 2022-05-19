#include "headers/player.h"
#include "headers/game.h"
#include "headers/points.h"
#include "headers/bullet.h"
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QBrush>
#include "headers/enemy.h"
#include <QDebug>

#define BORDER 300
#define STEP 10
int count = 0;

enum shoot {
    UP, DOWN, LEFT, RIGHT
};

extern Game *game;


Player::Player() {
    //setBrush(QBrush(Qt::red, Qt::SolidPattern));
    setPixmap(QPixmap("://pictures/png/player.png"));
    setPos(400, 520);
    setFlag(QGraphicsItem::ItemIsFocusable);
    setFocus();
    shootSound = new QMediaPlayer();
    shootSound->setMedia(QUrl("qrc://sounds/mp3/shoot.mp3"));
    shootSound->setVolume(10);
    eatSound = new QMediaPlayer();
    eatSound->setMedia(QUrl("qrc://sounds/mp3/eatsound.mp3"));
    eatSound->setVolume(10);
}

void Player::shoot(int direction) {
    if (direction == UP) {
        Bullet *bullet = new Bullet(UP);
        setTransformOriginPoint(90, 90);
        setRotation(90);
        bullet->setPos(x() + 70, y() + 90);
        scene()->addItem(bullet);
        shootSound->play();
    }
    else if (direction == DOWN) {
        Bullet *bullet = new Bullet(DOWN);
        setTransformOriginPoint(90, 90);
        setRotation(-90);
        bullet->setPos(x() + 73, y() + 80);
        scene()->addItem(bullet);
        shootSound->play();
        //qDebug() << "shoot down";
    }
    else if (direction == LEFT) {
        Bullet *bullet = new Bullet(LEFT);
        setTransformOriginPoint(90, 90);
        setRotation(0);
        bullet->setPos(x() + 73, y() + 85);
        shootSound->play();
        scene()->addItem(bullet);
    }
    else if (direction == RIGHT) {
        Bullet *bullet = new Bullet(RIGHT);
        setTransformOriginPoint(90, 90);
        setRotation(180);
        bullet->setPos(x() + 70, y() + 83);
        shootSound->play();
        scene()->addItem(bullet);
    }
}

void Player::keyPressEvent(QKeyEvent *event)
{
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; i++) {
        if (typeid(*(colliding_items[i])) == typeid(Points)) {
            eatSound->play();
            game->score->increase();
            scene()->removeItem(colliding_items[i]);
            //scene()->removeItem(this);
            delete colliding_items[i];
            //delete this;
            return;
        }
        if (typeid(*(colliding_items[i])) == typeid(Enemy)) {
            game->health->decrease();
            scene()->removeItem(colliding_items[i]);
            delete colliding_items[i];
            if (game->health->getHealth() <= 0) {
                scene()->removeItem(this);
                delete this;
            }
            return;
        }
    }
    if (event->key() == Qt::Key_W) {
        shoot(UP);
    }
    else if (event->key() == Qt::Key_S) {
        shoot(DOWN);
    }
    else if (event->key() == Qt::Key_D) {
        shoot(RIGHT);
    }
    else if (event->key() == Qt::Key_A) {
        shoot(LEFT);
    }
    else if (event->key() == Qt::Key_Left) {
        setTransformOriginPoint(90, 90);
        setRotation(0);
        if (x() > 0) {
            setPos(x() - STEP, y());
        }
    }
    else if (event->key() == Qt::Key_Right) {
        setTransformOriginPoint(90, 90);
        setRotation(180);
        if (x() + 75 < 800)
            setPos(x() + STEP, y());
    }
    else if (event->key() == Qt::Key_Up) {
        setTransformOriginPoint(90, 90);
        setRotation(90);
        if (y() > 0) {
            setPos(x(), y() - STEP);
        }
    }
    else if (event->key() == Qt::Key_Down) {
        setTransformOriginPoint(90, 90);
        setRotation(-90);
        if (y() + 75 < 600) {
            setPos(x(), y() + STEP);
        }
    }
}

void Player::spawnPoints() {
    Points *point = new Points();
    scene()->addItem(point);
}

void Player::spawnEnemy() {
    Enemy *enemy = new Enemy();
    scene()->addItem(enemy);
}
