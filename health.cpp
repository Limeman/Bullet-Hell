#include "health.h"
#include <QFont>
#include <QString>

Health::Health(QGraphicsTextItem *parent): QGraphicsTextItem(parent), health(5)
{
    setPlainText(QString("Health: " + QString::number(health)));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times", 16));
}
