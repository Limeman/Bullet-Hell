#ifndef GAME_H
#define GAME_H
#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include <QTimer>
#include "player.h"
#include "constants.h"
#include "health.h"
#include "score.h"

/*!
 * \brief The Game class, used to handle the game logic
 */
class Game: public QGraphicsView
{
public:
    //!Constructor
    Game();
    //!Retruns the Health QGraphicsTextItem
    Health *getHealth() {return health;}
    //!Returns the Score QGraphicsTextItem
    Score *getScore()   {return score;}
    //!returns the current level
    int getLevel() {return level;}
    //!Sets the level
    void setLevel(int arg)  {level = arg;}
    //!when the player health passes zero this function is invoked
    void gameOver();
private:
    Player *player;
    QGraphicsScene *scene = new QGraphicsScene();
    Constants constants;
    Health *health;
    QTimer *timer = new QTimer();
    QTimer *scoreTimer = new QTimer();
    Score *score = new Score();
    int level;
};

#endif // GAME_H
