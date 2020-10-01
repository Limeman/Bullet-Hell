#ifndef FINALBULLET_H
#define FINALBULLET_H
#include "bullet.h"
#include <QTimer>
#include <QMediaPlayer>
#include "game.h"

extern Game *game;

/*!
 * \brief The finalBullet class, inherits from the baseclass Bullet
 */
class finalBullet: public Bullet
{
    Q_OBJECT
public:
    //!constructor
    finalBullet();
public slots:
    //!moves the bullet
    void move();
};

#endif // FINALBULLET_H
