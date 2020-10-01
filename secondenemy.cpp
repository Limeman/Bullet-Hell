#include "secondenemy.h"
#include "enemybullet.h"
#include <QGraphicsScene>
#include <cstdlib>

secondEnemy::secondEnemy()
{
    srand(time(NULL));
    //randomize a position
    int random_number = 0;
    while (random_number < getConstants().secondEnemyWidth) {
        random_number = rand() % (getConstants().WIDTH - 88);
    }
    //set the position to the randomized position
    setPos(random_number, getConstants().ORIGIN);

    //set the image of the enemy to Enemy1.png
    setPixmap(QPixmap(":/Pictures/secondenemy.png"));

    //set the sound of the first enemy's bullet to enemy1.wav
    getSound()->setMedia(QUrl("qrc:/Sounds/secondenemy.wav"));


    //connect the timers to the move() and shoot() functions
    connect(getTimer(), SIGNAL(timeout()), this, SLOT(move()));
    connect(getShooterTimer(), SIGNAL(timeout()), this, SLOT(shoot()));

    //start the timers
    getTimer()->start(50);
    getShooterTimer()->start(2000);
}

secondEnemy::~secondEnemy()
{
    //when the secondEnemy is destructed, play it's death sound
    getSound()->play();
}

void secondEnemy::move()
{
    //randomize an x- velocity and assig a y velocity of 2
    setVelocity({rand() % 6 - 3, 4});
    if (pos().y() >= getConstants().HEIGHT + 88)   {
        scene()->removeItem(this);
        delete this;
        return;
    }
    //if the enemy is still on the screen
    else if (y() + 88 < getConstants().HEIGHT)   {
        //move
        setPos(x() + getVelocity().first, y() + getVelocity().second);
    }
    //if the enemy is on the corner of the screen, only move downwards
    else if (x() <= 0 || x() > getConstants().HEIGHT)
        //move
        setPos(x(), y() + getVelocity().second);
    //otherwise the enemy is out of scope, it must be destroyed
    else    {
        //remove the enemy from the scene
        scene()->removeItem(this);
        //delete the enemy
        delete this;
    }
}

void secondEnemy::shoot()    {
    //create a new bullet
    Bullet *bullet1 = new enemyBullet();

    //set the damage
    bullet1->setDamage(2);

    //set their positions
    bullet1->setPos(x(), y() + 96);


    //add them to the scene
    scene()->addItem(bullet1);
}
