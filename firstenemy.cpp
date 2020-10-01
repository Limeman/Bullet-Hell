#include "firstenemy.h"
#include "enemybullet.h"
#include <QGraphicsScene>
#include <cstdlib>
#include "game.h"

extern Game *game;

firstEnemy::firstEnemy()
{
    srand(time(NULL));
    int random_number = 0;
    //randomize a position
    while (random_number < 60)  {
        random_number = rand() % getConstants().WIDTH - 60;
    }
    //set the position to the randomized position
    setPos(random_number, 0);

    //set the image of the enemy to Enemy1.png
    setPixmap(QPixmap(":/Pictures/enemy1.png"));

    //set the sound of the first enemy's bullet to enemy1.wav
    getSound()->setMedia(QUrl("qrc:/Sounds/firstenemy.wav"));


    //connect the timers to the move() and shoot() functions
    connect(getTimer(), SIGNAL(timeout()), this, SLOT(move()));
    connect(getShooterTimer(), SIGNAL(timeout()), this, SLOT(shoot()));

    //start the timers
    getTimer()->start(50);
    getShooterTimer()->start(2000);
}

firstEnemy::~firstEnemy()
{
    //when the firstenemy is destructed, play it's death sound
    getSound()->play();
}

void firstEnemy::move()
{
    //if the enemy is on the screen
    if (y() + 74 < getConstants().HEIGHT)
        //move
        setPos(x(), y() + 2);
    //otherwise......
    else    {
        //decrease the player's health
        game->getHealth()->decrease(1);
        //refresh the amount of health the player has on the screen
        game->getHealth()->refreshHealth();
        //remove the enemy from the scene
        scene()->removeItem(this);
        //delete this object
        delete this;
    }
}

void firstEnemy::shoot()    {
    //create a new enemy bullet
    Bullet *bullet = new enemyBullet();
    //set the bullet's position to the middle top of the enemy
    bullet->setPos(x() + getConstants().firstEnemyWidth / 2, y() + getConstants().firstEnemyHeight);
    //add the bullet to the scene
    scene()->addItem(bullet);
}
