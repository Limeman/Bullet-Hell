#include "enemybullet.h"
#include <QGraphicsScene>
#include <QList>
#include "player.h"


enemyBullet::enemyBullet()
{
    //set the image of the bullet to enemybullet.png
    setPixmap(QPixmap(":/Pictures/enemybullet.png"));

    //set the sound of the bullet to enemybullet.wav
    getSound()->setMedia(QUrl("qrc:/Sounds/enemybullet.wav"));

    //set the velocity of the bullet
    setVelocity({0, 1});

    //connect the timer to the move() function
    connect(getTimer(), SIGNAL(timeout()), this, SLOT(move()));

    //start the timer
    getTimer()->start(1);

    setDamage(1);

    //play the bullets sound
    getSound()->play();
}

void enemyBullet::move()
{
    //if the bullet is outside of the window
    if (pos().y() > getConstants().HEIGHT)  {
        //remove the bullet from the scene
        scene()->removeItem(this);
        delete this;
        //return so that we don't access something that no longer exsists
        return;
    }
    //create a QList containg QGraphicsItem's that have collided
    QList<QGraphicsItem *> colliding_items = collidingItems();

    //if the enemyBullet has hit a player, decrease the player health
    if (playerContact(colliding_items, this)) {
        delete this;
        //return so that we don't move something that no longer exsists
        return;
    }
    //move
    setPos(x() + getVelocity().first, y() + getVelocity().second);
}


bool enemyBullet::playerContact(QList<QGraphicsItem *> arg, enemyBullet *kula) {
    //loop through the QList of colliding items
    for (auto elem: arg)    {
        //if the typid is a player
        if (typeid(*(elem)) == typeid(Player))  {
            //decrease the player health
            game->getHealth()->decrease(kula->getDamage());
            //refresh the health to show the new health on the screen
            game->getHealth()->refreshHealth();
            //since we hit a player, return true
            return true;
        }
    }
    //if no player was hit, return false
    return false;
}
