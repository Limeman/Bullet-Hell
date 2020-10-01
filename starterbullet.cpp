#include "starterbullet.h"
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h>
#include "firstenemy.h"

starterBullet::starterBullet()
{
    //set the bullets image to the image starterbullet.png
    setPixmap(QPixmap(":/Pictures/starterbullet.png"));

    //set the bullets sound to the sound starterbulletsound
    getSound()->setMedia(QUrl("qrc:/Sounds/starterbulletsound.wav"));

    //set the velocity of the bullet
    setVelocity({0, 1});

    //connect the timer timout signal to the move function
    connect(getTimer(), SIGNAL(timeout()), this, SLOT(move()));

    //start the timer with a peroid time of 1 second
    getTimer()->start(1);

}

void starterBullet::move()
{
    //randomize a velocity
    setVelocity({getVelocity().first, rand() % 6});
    //create a list of items that are colliding
    QList<QGraphicsItem *> colliding_items = collidingItems();

    //if the bullet collides with an enemy delete them both
    if  (contact(colliding_items, this)) {
        game->getScore()->increase(1);
        game->getScore()->refreshScore();
        return;
    }
    //move upwards in that randomized velocity
    setPos(x(), y() - getVelocity().second);
    //if the bullet is outside of the scene remove it and delete it
    if (pos().y() < 0)  {
        scene()->removeItem(this);
        delete this;
    }

}
