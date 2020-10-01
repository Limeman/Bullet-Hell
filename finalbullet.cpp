    #include "finalbullet.h"
    #include <QGraphicsScene>
    #include <stdlib.h>
    #include "firstenemy.h"
    #include "game.h"

    extern Game *game;

    finalBullet::finalBullet()
    {
        //set the image of the bullet to finalbullet.png
        setPixmap(QPixmap(":/Pictures/finalbullet.png"));

        //set the sound of the bullet to finalbullet.wav
        getSound()->setMedia(QUrl("qrc:/Sounds/finalbullet.wav"));

        //set the velocity of the bullet
        setVelocity({12, 4});

        //connect the timer to the move() function
        connect(getTimer(), SIGNAL(timeout()), this, SLOT(move()));

        //start the timer
        getTimer()->start(1);
    }

    void finalBullet::move()
    {
        srand(time(NULL));
        int randomNumber = rand() %2 + 1;

        QList<QGraphicsItem *> colliding_items = collidingItems();

        //if the bullet collides with an enemy delete them both
        if (contact(colliding_items, this)) {
            game->getScore()->increase(4);
            game->getScore()->refreshScore();
            return;
        }
        //if even number
        if (randomNumber % 2)   {
            //move right and down
            setPos(x() + getVelocity().first, y() - getVelocity().second);
        }
        //otherwise...
        else    {
            //move left and down
            setPos(x() - getVelocity().first, y() - getVelocity().second);
        }
    }
