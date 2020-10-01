#ifndef HEALTH_H
#define HEALTH_H
#include <QGraphicsTextItem>

/*!
 * \brief The Health class, inherits from QGraphicsTextItem
 */
class Health: public QGraphicsTextItem
{
public:
    //!constructor
    Health(QGraphicsTextItem *parent = 0);
    //!returns the amount of health the player has
    int getHealth() {return health;}
    //!decreases the player helath
    void decrease(int arg) {health = health - arg;}
    //!refreshes the screen when the amount of health is changed
    void refreshHealth()    {setPlainText(QString("Health: " + QString::number(health)));}
private:
    int health;
};

#endif // HEALTH_H
