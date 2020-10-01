#ifndef SCORE_H
#define SCORE_H
#include <QGraphicsTextItem>

/*!
 * \brief The Score class, inherits from QGraphicsTextItem
 */
class Score: public QGraphicsTextItem
{
public:
    //!constructor
    Score(QGraphicsTextItem *parent = 0);
    //!increases the player score
    void increase(int arg) {score = score + arg;}
    //!returns the player score
    int getScore() {return score;}
    //!refreshes the score when the score is changed
    void refreshScore() {setPlainText(QString("Score: " + QString::number(score)));}
private:
    int score;
};

#endif // SCORE_H
