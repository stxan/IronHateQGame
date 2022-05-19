#ifndef POINTS_H
#define POINTS_H
#include <QGraphicsEllipseItem>
#include <QObject>
#include <QMediaPlayer>

class Points: public QObject, public QGraphicsEllipseItem {
    Q_OBJECT
public:
    Points();
private:
    QMediaPlayer *points_spawn_sound;

};

#endif // POINTS_H
