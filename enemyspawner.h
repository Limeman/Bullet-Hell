#ifndef ENEMYSPAWNER_H
#define ENEMYSPAWNER_H
#include <QTimer>
#include <QObject>
#include <cstdlib>
#include "firstenemy.h"


class enemySpawner: public firstEnemy
{
    Q_OBJECT
public:
    enemySpawner();
    void toggleLevel(int arg);
public slots:
    void spawn();
private:
    bool level_1, level_2, level_3;
};

#endif // ENEMYSPAWNER_H
