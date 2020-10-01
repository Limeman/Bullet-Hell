#include "bullet.h"
#include "firstenemy.h"
#include "secondenemy.h"
#include "finalenemy.h"
#include <QGraphicsScene>
#include <typeinfo>


bool Bullet::contact(QList<QGraphicsItem *> arg, QGraphicsItem *kula)
{
    //loop through all the colliding items
    for (auto elem: arg)    {
        //if one of the items is an enemy
        if (typeid(*(elem)) == typeid(firstEnemy) || typeid(*(elem)) == typeid(secondEnemy) || typeid(*(elem)) == typeid(finalEnemy))   {
            //remove them from the scene
            scene()->removeItem(elem);
            scene()->removeItem(kula);
            //deelte them
            delete elem;
            delete kula;
            //return so that we don't set a position on something that no longer exsists
            return true;
        }
    }
    return false;
}
