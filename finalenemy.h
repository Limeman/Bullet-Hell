#ifndef FINALENEMY_H
#define FINALENEMY_H
#include "enemy.h"

/*!
 * \brief The finalEnemy class, inherits from the baseclass Enemy
 */
class finalEnemy: public Enemy
{
    Q_OBJECT
public:
    //!constructor
    finalEnemy();
public slots:
    //!moves the enemy
    void move();
    //!when the enemy shoots, this function is invoked
    void shoot();
};

#endif // FINALENEMY_H
