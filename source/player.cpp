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
#define SPAWN_POS_X 400
#define SPAWN_POS_Y 520
#define ROTATE_PIE_2 90
#define ROTATE_PIE 180
#define BORDER_CHECK_W 800
#define BORDER_CHECK_H 600
#define BORDER_CHECK_DELTA 75
#define PLAYER_MIDDLE 90
#define SHOOT_UP_BULLETSPAWN_X_OFFSET 70
#define SHOOT_UP_BULLETSPAWN_Y_OFFSET 90
#define SHOOT_DOWN_BULLETSPAWN_X_OFFSET 73
#define SHOOT_DOWN_BULLETSPAWN_Y_OFFSET 80
#define SHOOT_LEFT_BULLETSPAWN_X_OFFSET 73
#define SHOOT_LEFT_BULLETSPAWN_Y_OFFSET 85
#define SHOOT_RIGHT_BULLETSPAWN_X_OFFSET 70
#define SHOOT_RIGHT_BULLETSPAWN_Y_OFFSET 83


int count = 0;

enum shoot {
    UP, DOWN, LEFT, RIGHT
};

extern Game *game;


Player::Player() {
    //setBrush(QBrush(Qt::red, Qt::SolidPattern));
    setPixmap(QPixmap("://pictures/png/player.png"));
    setPos(SPAWN_POS_X, SPAWN_POS_Y);
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
        setTransformOriginPoint(PLAYER_MIDDLE, PLAYER_MIDDLE);
        setRotation(ROTATE_PIE_2);
        bullet->setPos(x() + SHOOT_UP_BULLETSPAWN_X_OFFSET, y() + SHOOT_UP_BULLETSPAWN_Y_OFFSET);
        scene()->addItem(bullet);
        shootSound->play();
    }
    else if (direction == DOWN) {
        Bullet *bullet = new Bullet(DOWN);
        setTransformOriginPoint(PLAYER_MIDDLE, PLAYER_MIDDLE);
        setRotation(-ROTATE_PIE_2);
        bullet->setPos(x() + SHOOT_DOWN_BULLETSPAWN_X_OFFSET, y() + SHOOT_DOWN_BULLETSPAWN_Y_OFFSET);
        scene()->addItem(bullet);
        shootSound->play();
        //qDebug() << "shoot down";
    }
    else if (direction == LEFT) {
        Bullet *bullet = new Bullet(LEFT);
        setTransformOriginPoint(PLAYER_MIDDLE, PLAYER_MIDDLE);
        setRotation(0);
        bullet->setPos(x() + SHOOT_LEFT_BULLETSPAWN_X_OFFSET, y() + SHOOT_LEFT_BULLETSPAWN_Y_OFFSET);
        shootSound->play();
        scene()->addItem(bullet);
    }
    else if (direction == RIGHT) {
        Bullet *bullet = new Bullet(RIGHT);
        setTransformOriginPoint(PLAYER_MIDDLE, PLAYER_MIDDLE);
        setRotation(ROTATE_PIE);
        bullet->setPos(x() + SHOOT_RIGHT_BULLETSPAWN_X_OFFSET, y() + SHOOT_RIGHT_BULLETSPAWN_Y_OFFSET);
        shootSound->play();
        scene()->addItem(bullet);
    }
}

void Player::keyPressEvent(QKeyEvent *event)
{
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; i++) {
        if (dynamic_cast<Points *>(colliding_items[i])) {
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
        setTransformOriginPoint(PLAYER_MIDDLE, PLAYER_MIDDLE);
        setRotation(0);
        if (x() > 0) {
            setPos(x() - STEP, y());
        }
    }
    else if (event->key() == Qt::Key_Right) {
        setTransformOriginPoint(PLAYER_MIDDLE, PLAYER_MIDDLE);
        setRotation(ROTATE_PIE);
        if (x() + BORDER_CHECK_DELTA < BORDER_CHECK_W)
            setPos(x() + STEP, y());
    }
    else if (event->key() == Qt::Key_Up) {
        setTransformOriginPoint(PLAYER_MIDDLE, PLAYER_MIDDLE);
        setRotation(ROTATE_PIE_2);
        if (y() > 0) {
            setPos(x(), y() - STEP);
        }
    }
    else if (event->key() == Qt::Key_Down) {
        setTransformOriginPoint(PLAYER_MIDDLE, PLAYER_MIDDLE);
        setRotation(-ROTATE_PIE_2);
        if (y() + BORDER_CHECK_DELTA < BORDER_CHECK_H) {
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
