#ifndef BULLET_H
#define BULLET_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QTimer>
#include <utility>
#include "soundplayer.h"
#include "constants.h"
#include "game.h"

extern Game *game;

//!Bullet base class
/*!
* Bullet base class.
*
* Inherits from QObject, QGraphicsPixItem and soundPlayer.
*/
class Bullet: public QObject, public QGraphicsPixmapItem, public soundPlayer
{
    Q_OBJECT
public:
    //!plays the bulletSound  QMediaPlayer object with the boom() function from soundPlayer
    void playSound() {boom(bulletSound);}

    //!Returns the amount of damage that a bullet inflicts
    int getDamage() {return damage;}
    //!Sets the amount of damage that a bullet inflcits
    void setDamage(int arg) {damage = arg;}

    //!Returns the velocity of a bullet
    std::pair<int, int> getVelocity() {return velocity;}
    //!Sets the velocity of a bullet
    void setVelocity(std::pair<int, int> arg) {velocity.first = arg.first; velocity.second = arg.second;}

    //!Returns a pointer to the QMediaPlayer object bulletSound (eg. the variable that plays the bullet's sound)
    QMediaPlayer *getSound() {return bulletSound;}
    //!Used to set the bulletSound to the QMediaPlayer object that is sent in
    void setSound(QMediaPlayer *arg) {bulletSound = arg;}

    //!Returns a pointer to the QMediaPlayer object timer
    QTimer *getTimer() {return timer;}
    //!Used to set the timer to the QMediaPlayer that is sent in
    void setTimer(QTimer *arg) {timer = arg;}
    //!Returns the constants of the game
    Constants getConstants() {return constants;}

    //!Deletes objects that collide with bullets
    bool contact(QList<QGraphicsItem *> arg, QGraphicsItem *kula);

public slots:
    //!will define the movement in the subclasses
    virtual void move() = 0;
private:
    int damage;
    std::pair<int, int> velocity;
    QMediaPlayer *bulletSound = new QMediaPlayer();
    QTimer *timer = new QTimer();
    Constants constants;
};

#endif // BULLET_H
