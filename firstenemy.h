#ifndef FIRSTENEMY_H
#define FIRSTENEMY_H
#include "enemy.h"
#include <QMediaPlayer>
#include <QTimer>

/*!
 * \brief The firstEnemy class, inherits from the baseclass Enemy
 */
class firstEnemy: public Enemy
{
    Q_OBJECT
public:
    //!constructor
    firstEnemy();
    //!destructor
    ~firstEnemy();
public slots:
    //!moves the enemy
    void move();
    //!wen the enemy shoots this function is invoked
    void shoot();
};

#endif // FIRSTENEMY_H
