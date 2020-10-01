#ifndef SECONDBULLET_H
#define SECONDBULLET_H
#include "bullet.h"
#include <QTimer>
#include <QMediaPlayer>

/*!
 * \brief The secondBullet class, inherits from the baseclass Bullet
 */
class secondBullet: public Bullet
{
    Q_OBJECT
public:
    //!constructor
    secondBullet();
public slots:
    //!moves the bullet
    void move();
};

#endif // SECONDBULLET_H
