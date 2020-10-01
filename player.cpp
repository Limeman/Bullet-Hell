#include "player.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include "starterbullet.h"
#include "secondbullet.h"
#include "finalbullet.h"
#include "firstenemy.h"
#include "secondenemy.h"
#include "finalenemy.h"
#include "game.h"

extern Game *game;


Player::Player(QGraphicsPixmapItem *parent):
    QGraphicsPixmapItem(parent),
    velocity(1),
    timer(new QTimer())
{
    //set the image of the player to ship.png
    setPixmap(QPixmap(":/Pictures/ship.png"));
    //connect the timer timeout() signal to the slot movePlayer()
    connect(timer, SIGNAL(timeout()), this, SLOT(movePlayer()));
    //start the timer with an intervall of 2ms
    timer->start(2);
}

void Player::keyPressEvent(QKeyEvent *event)
{
    //if the user presses the left key....
    if (event->key() == Qt::Key_Left)   {
        //move to the left
        direction = 1;
    }
    //if the user presses the right key.....
    else if (event->key() == Qt::Key_Right) {
            //move right
            direction = 2;
    }
    else if (event->key() == Qt::Key_Space) {
        //create a new bullet pointer
        Bullet *bullet;
        //depending on what level the player is at
        switch (game->getLevel()) {
        //if on the first level, create a new starterbullet
        case 1:
            bullet = new starterBullet();
            break;
        //if on the second level, create a new secondBullet
        case 2:
            bullet = new secondBullet();
            break;
        //if on the final level, create a new finalBullet
        case 3:
            bullet = new finalBullet();
            break;
        default:
            //if no valid level is given create a new starterBullet
            bullet = new starterBullet();
            break;
        }

        //play the bullet's sound
        bullet->playSound();
        //set the position of the bullet
        bullet->setPos(x() + constants.playerWidth / 2 - 10, y());
        //add the bullet to the scene
        scene()->addItem(bullet);
    }
    else if (event->key() == Qt::Key_Up)    {
        //put the ship in a resting position
        direction = 0;
    }
    else    {
        //otherwise, do nothing
    }
}

void Player::movePlayer()
{
    //if the direction is set to 1
    if (direction == 1)  {
        //if the position is not off the screen
        if (pos().x() > constants.ORIGIN) {
            //move to the left
            setPos(x() - velocity, y());
        }
    }
    // if the direction is set to 2
    else if (direction == 2){
        //if the position is not off the screen
        if (pos().x() < constants.WIDTH - 50) {
            //move to the right
            setPos(x() + velocity, y());
        }
    }
    else    {
        //otherwise do nothing
    }
}

void Player::spawn()
{
    //if the player is on the first level
    if (game->getLevel() == 1)  {
        //create first enemies
        Enemy *enemy = new firstEnemy();
        scene()->addItem(enemy);
    }
    //if the player is on the second level
    else if (game->getLevel() == 2) {
        //create second enemies
        Enemy *enemy = new secondEnemy();
        scene()->addItem(enemy);
    }
    //if the player is on the thrid and final level
    else if (game->getLevel() == 3) {
        //create final enemies
        Enemy *enemy = new finalEnemy();
        scene()->addItem(enemy);
    }
    //if the level is something that makes no sense
    else {
        //create first enemies
        Enemy *enemy = new firstEnemy();
        scene()->addItem(enemy);
    }
}

void Player::checkScore()
{
    if (game->getScore()->getScore() > 30)  {
        //player wins the game
    }
    else if (game->getScore()->getScore() > 20) {
        //player gets to the third and final level
        game->setLevel(3);
    }
    else if (game->getScore()->getScore() > 10)  {
        //player gets to the second level
        game->setLevel(2);
    }
    else {
        //nothing changes
    }
}

void Player::checkHealth()
{
    //if the player health is less or equal to zero
    if (game->getHealth()->getHealth() <= 0)    {
        //end the game
        game->gameOver();
    }
}
