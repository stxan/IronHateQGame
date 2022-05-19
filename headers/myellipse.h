#ifndef MYELLIP_H
#define MYELLIP_H

#include <QGraphicsEllipseItem>
#include <QObject>
class myEllipse : public QObject, public QGraphicsEllipseItem {
    Q_OBJECT
public:
    void keyPressEvent(QKeyEvent *event);
public slots:
    void spawnEnemy();
};

#endif
