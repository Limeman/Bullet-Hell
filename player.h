#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QMediaPlayer>
#include <QObject>
#include <QTimer>
#include "constants.h"

/*!
 * \brief The Player class, handles player logic and is used to spawn enemies
 */
class Player : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    //!Constructor
    Player(QGraphicsPixmapItem *parent = 0);
    //!keyPressEvent
    //! Used to take input form the player
    void keyPressEvent(QKeyEvent *event);
public slots:
    //!moves the player
    void movePlayer();
    //!spawns enemys
    void spawn();
    //!checks the score, increases the level when points are high enough
    void checkScore();
    //!Checks the player health
    void checkHealth();
private:
    Constants constants;
    size_t velocity;
    QTimer *timer;
    int direction;

};

#endif // PLAYER_H
