#include "game.h"
#include "firstenemy.h"
#include <QGraphicsTextItem>

Game::Game():
    player(new Player()),
    level(1)
{
    //set the size of the scene
    scene->setSceneRect(constants.ORIGIN,constants.ORIGIN,constants.WIDTH, constants.HEIGHT);

    //make scene the scene to be visualized
    setScene(scene);

    //set the screen background color to black
    setBackgroundBrush(QBrush(Qt::black, Qt::SolidPattern));

    //Turn off the scrollbars
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    //add the player object to the scene
    scene->addItem(player);

    //lock the size to 1280 x 720
    setFixedSize(constants.WIDTH, constants.HEIGHT);

    //set a posistion for the player
    player->setPos(constants.WIDTH / 2, constants.HEIGHT - 67);

    //since the player object is what will respond to user input
    //focus needs to be set to the player object
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    //Initialize player health
    health = new Health();

    //set the position of the health
    health->setPos(constants.ORIGIN, constants.ORIGIN);

    //add the health object to the scene
    scene->addItem(health);

    //set the position of the score
    score->setPos(constants.ORIGIN, 16);

    //ad the score to the screen
    scene->addItem(score);

    QObject::connect(timer, SIGNAL(timeout()), player, SLOT(spawn()));
    QObject::connect(scoreTimer, SIGNAL(timeout()), player, SLOT(checkScore()));
    QObject::connect(scoreTimer, SIGNAL(timeout()), player, SLOT(checkHealth()));

    //start the timers
    timer->start(5000);
    scoreTimer->start(1000);
    //show the scene to the user
    show();

}

void Game::gameOver()
{
    //clear the scene
    scene->clear();
    //generate a game over message
    QGraphicsTextItem * io = new QGraphicsTextItem();
    io->setPos(constants.WIDTH / 2, constants.HEIGHT / 2);
    io->setPlainText(QString("Game over your score was: " + QString::number(score->getScore())));
    io->setDefaultTextColor(Qt::red);
    io->setFont(QFont("times", 16));
    //add the gameover message to the screen
    scene->addItem(io);
}
