#include "score.h"
#include <QFont>

Score::Score(QGraphicsTextItem *parent): QGraphicsTextItem(parent), score(0)
{
    setPlainText(QString("Score: " + QString::number(score)));
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times", 16));
}
