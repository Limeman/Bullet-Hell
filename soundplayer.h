#ifndef SOUNDPLAYER_H
#define SOUNDPLAYER_H
#include <QMediaPlayer>

/*!
 * \brief The soundPlayer class, used to play sounds
 */
class soundPlayer
{
public:
    //!boom function, takes a QMediaPlayer pointer as an argument and plays it's sound
    void boom(QMediaPlayer *arg) {
        //if the arg is playing, that means that it has to be reset to the start
        //otherwise the file will be played from it's latest position and play it
        if (arg->state() == QMediaPlayer::PlayingState)  {
            arg->setPosition(0);
            arg->play();
        }
        //otherwise play the arg
        else    {
            arg->play();
        }

    }
};

#endif // SOUNDPLAYER_H
