#include "headers/score.h"
#include <QFont>

#define TEXT_SIZE 16

Score::Score(QGraphicsItem *parent): QGraphicsTextItem(parent){
    score = 0;

    setPlainText(QString("Score: ") + QString::number(score));
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times", TEXT_SIZE));
}

void Score::increase(){
    score++;
    setPlainText(QString("Score: ") + QString::number(score));
}



int Score::getScore(){
    return score;
}
