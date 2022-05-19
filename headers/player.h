#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QMediaPlayer>

class Player : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    void shoot(int direction);
    Player();
    void keyPressEvent(QKeyEvent *event);
public slots:
    void spawnEnemy();
    void spawnPoints();
private:
    QMediaPlayer *eatSound;
    QMediaPlayer *shootSound;
};

#endif
