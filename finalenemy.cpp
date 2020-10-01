#include "finalenemy.h"
#include "game.h"
#include "enemybullet.h"
#include <cstdlib>

extern Game *game;

finalEnemy::finalEnemy()
{
    srand(time(NULL));
    //randomize a position
    int random_number = -1;
    while (random_number < 0)  {
        random_number = rand() % getConstants().WIDTH - getConstants().finalEnemyWidth;
    }

    //set the position to the randomized position
    setPos(random_number, getConstants().ORIGIN);

    //set the image to finalenemy.png
    setPixmap(QPixmap(":/Pictures/finalenemy.png"));
    //set the sound to finalenemy.mp3
    getSound()->setMedia(QUrl("qrc:/Sounds/finalenemy.wav"));

    //set the velocity of the enemy
    setVelocity({0, 12});

    //connect the move and shoot timers to the move() and shoot() slots
    connect(getTimer(), SIGNAL(timeout()), this, SLOT(move()));
    connect(getShooterTimer(), SIGNAL(timeout()), this, SLOT(shoot()));

    //play the enemy sound
    getSound()->play();

    //start the timers
    getTimer()->start(50);
    getShooterTimer()->start(500);
}

void finalEnemy::move()
{
    //if the enemy is on the screen
    if (pos().y() < getConstants().HEIGHT - 100)    {
        //move
        setPos(x(), y() + getVelocity().second);
    }
    //otherwise......
    else    {
        //decrease the player's health
        game->getHealth()->decrease(3);
        //refresh the amount of health the player has on the screen
        game->getHealth()->refreshHealth();
        //remove this enemy from the scene
        scene()->removeItem(this);
        //delete this enemy
        delete this;
    }
}

void finalEnemy::shoot()
{
    //create a new enemyBullet
    Bullet *bullet = new enemyBullet();

    //set it's damage to 3
    bullet->setDamage(3);

    //set the position of the bullet
    bullet->setPos(x() + 43, y() + 100);
    //add the bullet to the scene
    scene()->addItem(bullet);
}
