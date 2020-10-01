#ifndef STARTERBULLET_H
#define STARTERBULLET_H
#include "bullet.h"
#include <QTimer>
#include <QMediaPlayer>

/*!
 * \brief The starterBullet class, inherits from the baseclass Bullet
 */
class starterBullet: public Bullet
{
    Q_OBJECT
public:
    //!constructor
    starterBullet();
public slots:
    //!moves the bullet
    void move();
};

#endif // STARTERBULLET_H
