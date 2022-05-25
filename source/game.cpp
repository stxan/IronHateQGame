#include "headers/game.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include "headers/enemy.h"
#include "headers/player.h"
#include "headers/health.h"
#include "headers/score.h"
#include <QMediaPlayer>
#include "headers/points.h"

int points_count = 0;

#define WINDOW_SIZE_W 800
#define WINDOW_SIZE_H 600
#define TEXT_OFFSET 25
#define TEXT_SIZE 16
#define RULES_POS_X (WINDOW_SIZE_W - 100) / 2
#define RULES_POS_Y 0
#define POINTS_SPAWN_FREQ 1000
#define ENEMIES_SPAWN_FREQ 10000

Game::Game(QWidget *parent){

    scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, WINDOW_SIZE_W, WINDOW_SIZE_H);
    setBackgroundBrush(QBrush(Qt::gray, Qt::SolidPattern));
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(WINDOW_SIZE_W, WINDOW_SIZE_H);

    QGraphicsTextItem *rules = new QGraphicsTextItem();
    rules->setPlainText(QString("Movement: ArrUp, ArrDown, ArrRight, ArrLeft\n") + QString("Shoot: W, A, S, D\n") + QString("Pick up green balls and shoot iron masks"));
    rules->setDefaultTextColor(Qt::green);
    rules->setFont(QFont("times", TEXT_SIZE));
    rules->setPos(RULES_POS_X, RULES_POS_Y);
    scene->addItem(rules);

    player = new Player();
    scene->addItem(player);

    score = new Score();
    scene->addItem(score);
    health = new Health();
    health->setPos(health->x(), health->y() + TEXT_OFFSET);
    scene->addItem(health);


    QTimer * timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()), player, SLOT(spawnPoints()));
    timer->start(POINTS_SPAWN_FREQ);
    points_count++;

    QTimer *timer_enemy = new QTimer();
    QObject::connect(timer_enemy, SIGNAL(timeout()), player, SLOT(spawnEnemy()));
    timer_enemy->start(ENEMIES_SPAWN_FREQ);

    QMediaPlayer *music = new QMediaPlayer();
    music->setMedia(QUrl("qrc://sounds/mp3/background"));
    music->setVolume(50);
    music->play();

    show();
}
