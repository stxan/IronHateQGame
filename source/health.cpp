#include "headers/health.h"
#include <QFont>

#define TEXT_SIZE 16

Health::Health(QGraphicsItem *parent): QGraphicsTextItem(parent){
    health = 3;

    setPlainText(QString("Health: ") + QString::number(health));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",TEXT_SIZE));
}

void Health::decrease(){
    health--;
    setPlainText(QString("Health: ") + QString::number(health));
}

int Health::getHealth(){
    return health;
}
