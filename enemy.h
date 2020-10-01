#ifndef ENEMY_H
#define ENEMY_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include <utility>
#include <QTimer>
#include <QMediaPlayer>
#include "soundplayer.h"
#include "constants.h"


/*!
 * \brief The Enemy class, base class for all enemy objects
 */
class Enemy: public QObject, public QGraphicsPixmapItem, public soundPlayer
{
    Q_OBJECT
public:
    //!Plays the sound that the enemy emits whwn it shoots a bullet
    void playSound(QMediaPlayer *arg) { boom(arg); }

    //!Returns the velocity of the enemy
    std::pair<int, int> getVelocity() {return velocity;}
    //!Sets the velocity of the enemy
    void setVelocity(std::pair<int, int> arg) {velocity.first = arg.first; velocity.second = arg.second;}

    //!Returns a pointer to the timer
    QTimer *getTimer() {return timer;}
    //!Sets the timer
    void setTimer(QTimer *arg) {timer = arg;}

    //!Returns a pointer to the QMediaPlayer explosionSound
    QMediaPlayer *getSound() {return explosionSound;}
    //!Sets the sound
    void setSound(QMediaPlayer *arg) {explosionSound = arg;}

    //!Returns the amount of damage that an enemy inflicts
    int getDamage() {return damage;}
    //!Sets the damage
    void setDamage( int &arg) {damage = arg;}

    //!Returns a pointer to the QTimer shooterTimer
    QTimer *getShooterTimer()  {return shooterTimer;}
    //!Set the QTimer shooterTimer
    void  setShooterTimer(QTimer *arg) {shooterTimer = arg;}

    //!Returns the constants
    Constants getConstants()    {return constants;}

public slots:
    //!Will move the enemy object in the subclasses
    virtual void move() = 0;
    //!Will make the enemy shoot a bullet in the subclasses
    virtual void shoot() = 0;

private:
    std::pair<int, int> velocity;
    QMediaPlayer *explosionSound = new QMediaPlayer();
    QTimer *timer = new QTimer();
    QTimer *shooterTimer = new QTimer();
    int damage;
    Constants constants;
};

#endif // ENEMY_H
