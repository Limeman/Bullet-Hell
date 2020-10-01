#ifndef CONSTANTS_H
#define CONSTANTS_H
#include <cstdlib>
/*!
 * \brief The Constants struct, used to access numbers that are constant throughout the program
 */
struct Constants {
    //!WIDTH represents the width of the scene
    const size_t WIDTH = 900;
    //!HEIGHT represents the height of the scene
    const size_t HEIGHT = 700;
    //!ORIGIN is used to represent the origin (eg. the point(0, 0))
    const size_t ORIGIN = 0;
    //!the height of the firstEnemy object's photo
    const size_t firstEnemyHeight = 60;
    //!the width of the firstEnemy object's photo
    const size_t firstEnemyWidth = 74;
    //!the height of the secondEnemy object's photo
    const size_t secondEnemyHeight = 96;
    //!the width of the secondEnemy object's photo
    const size_t secondEnemyWidth = 88;
    //!the height of the finalEnemy object's photo
    const size_t finalEnemyHeight = 100;
    //!the width of the finalEnemy object's photo
    const size_t finalEnemyWidth = 86;
    //!the size of the enemyBullet (the enemyBullet is the same size in both the x and y axis)
    const size_t enemyBulletSize = 10;
    //!the size of the starterBullet (the starterBullet is the same size in both the x and the y axis)
    const size_t starterBulletSize = 16;
    //!the size of the secondBullet
    const size_t secondBulletSize = 60;
    //!the height of the finaBullet
    const size_t finalBulletHeight = 130;
    //!the width of the finalBullet
    const size_t finalBulletWidth = 115;
    //!the height of the Player
    const size_t playerHeight = 67;
    //!the width of the Player
    const size_t playerWidth = 50;

};
#endif // CONSTANTS_H
