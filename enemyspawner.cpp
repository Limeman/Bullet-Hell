#include "enemyspawner.h"
#include <QGraphicsView>
#include <cstdlib>


enemySpawner::enemySpawner():
    level_1(true),
    level_2(false),
    level_3(false)
{
}

void enemySpawner::toggleLevel(int arg)
{
    if  (arg == 1)  {
        level_1 = true;
        level_2 = false;
        level_3 = false;
    }
    else if (arg == 2)  {
        level_2 = true;
        level_1 = false;
        level_3 = false;
    }
    else if (arg == 3)  {
        level_3 = true;
        level_1 = false;
        level_2 = false;
    }
    else {

    }
}

void enemySpawner::spawn()  {
    //if the user is on the first level
    if (level_1)    {
        //create a new firstEnemy
        firstEnemy *enemy = new firstEnemy();

        //set the enemy to that position
        enemy->setPos(rand() %getConstants().WIDTH, getConstants().ORIGIN);
        //add the firstEnemy to the scene
        scene()->addItem(enemy);
    }
    else if (level_2)   {

    }
    else   {

    }
}
