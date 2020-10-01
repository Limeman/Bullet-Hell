#include "secondbullet.h"
#include <QGraphicsScene>
#include <cstdlib>
#include "firstenemy.h"

secondBullet::secondBullet()
{
    //set the image of the bullet to the image secondbullet.png
    setPixmap(QPixmap(":/Pictures/secondbullet.png"));

    //set the bullet's sound to the soundfile secondbullet.wav
    getSound()->setMedia(QUrl("qrc:/Sounds/secondbullet.wav"));

    //set the velocity of the bullet
    setVelocity({2, 1});

    //connect the timer timout signal to the move function
    connect(getTimer(), SIGNAL(timeout()), this, SLOT(move()));

    //start the timer with a peroid time of 1 second
    getTimer()->start(1);

}

void secondBullet::move()
{
    //randomize between one or two
    int randomNum = rand() %2 + 1;

    QList<QGraphicsItem *> colliding_items = collidingItems();

    //if the bullet collides with an enemy delete them both
    if  (contact(colliding_items, this)) {
        game->getScore()->increase(2);
        game->getScore()->refreshScore();
        return;
    }
    //if two move left and up
    if  (randomNum % 2 == 0) {
        setPos(x() - getVelocity().first, y() - getVelocity().second);
    }
    //otherwise move right and up
    else {
        setPos(x() + getVelocity().first, y() - getVelocity().second);
    }
    //if the bullet is outside of the scene remove it and delete it
    if (pos().y() < 0)  {
        scene()->removeItem(this);
        delete this;
    }

}
