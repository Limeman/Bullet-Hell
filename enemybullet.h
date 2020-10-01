#ifndef ENEMYBULLET_H
#define ENEMYBULLET_H
#include "bullet.h"
#include "game.h"


extern Game *game;

/*!
 * \brief The enemyBullet class, inherits from the baseclass Bullet
 */
class enemyBullet: public Bullet
{
public:
    enemyBullet();

    //!When a bullet hits the player
    /*!
     * \brief playerContact
     * \param arg
     * \param kula
     * \return
     * True if the player has been hit, False if not
     * \details
     * Traverse the QList (arg) of collidingItems
     * If the player has been hit, decrease the players health.
     */
    bool playerContact(QList<QGraphicsItem *> arg, enemyBullet *kula);
private slots:
    void move();
};

#endif // ENEMYBULLET_H
