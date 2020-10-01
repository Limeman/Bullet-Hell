#ifndef SECONDENEMY_H
#define SECONDENEMY_H
#include "enemy.h"
#include <QMediaPlayer>
#include <QTimer>

/*!
 * \brief The secondEnemy class, inherits from the baseclass Enemy
 */
class secondEnemy: public Enemy
{
    Q_OBJECT
public:
    //!constructor
    secondEnemy();
    //!destructor
    ~secondEnemy();
public slots:
    //!moves the enemy
    void move();
    //!when the enemy shoots this function is invoked
    void shoot();
};

#endif // SECONDENEMY_H
