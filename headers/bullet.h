#ifndef BULLET_H
#define BULLET_H
#include <QGraphicsEllipseItem>
#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>

class Bullet: public QObject, public QGraphicsEllipseItem {
    Q_OBJECT
public:
    Bullet();
    Bullet(int direction);
public slots:
    void move();
private:
    int direction;
};

#endif // BULLET_H
