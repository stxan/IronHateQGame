#include "game.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include "enemy.h"
#include "player.h"
#include "health.h"
#include "score.h"
#include <QMediaPlayer>
#include "points.h"

int points_count = 0;

Game::Game(QWidget *parent){

    scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, 800, 600);
    setBackgroundBrush(QBrush(Qt::gray, Qt::SolidPattern));
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800, 600);

    QGraphicsTextItem *rules = new QGraphicsTextItem();
    rules->setPlainText(QString("Movement: ArrUp, ArrDown, ArrRight, ArrLeft\n") + QString("Shoot: W, A, S, D\n") + QString("Pick up green balls and shoot iron masks"));
    rules->setDefaultTextColor(Qt::green);
    rules->setFont(QFont("times",16));
    rules->setPos(350, 0);
    scene->addItem(rules);

    player = new Player();
    scene->addItem(player);

    score = new Score();
    scene->addItem(score);
    health = new Health();
    health->setPos(health->x(), health->y() + 25);
    scene->addItem(health);


    QTimer * timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()), player, SLOT(spawnPoints()));
    timer->start(5000);
    points_count++;

    QTimer *timer_enemy = new QTimer();
    QObject::connect(timer_enemy, SIGNAL(timeout()), player, SLOT(spawnEnemy()));
    timer_enemy->start(10000);

    QMediaPlayer *music = new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sounds/background"));
    music->setVolume(50);
    music->play();

    show();
}
