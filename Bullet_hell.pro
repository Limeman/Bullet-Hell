#-------------------------------------------------
#
# Project created by QtCreator 2017-01-03T14:37:33
#
#-------------------------------------------------

QT       += core gui\
        multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Bullet_hell
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        player.cpp \
    game.cpp \
    bullet.cpp \
    starterbullet.cpp \
    secondbullet.cpp \
    finalbullet.cpp \
    enemy.cpp \
    firstenemy.cpp \
    enemybullet.cpp \
    health.cpp \
    score.cpp \
    secondenemy.cpp \
    finalenemy.cpp

HEADERS  += player.h \
    game.h \
    constants.h \
    bullet.h \
    starterbullet.h \
    secondbullet.h \
    finalbullet.h \
    soundplayer.h \
    enemy.h \
    firstenemy.h \
    enemybullet.h \
    health.h \
    score.h \
    secondenemy.h \
    finalenemy.h

RESOURCES += \
    resources.qrc


