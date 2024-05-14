#ifndef PLAYER_H
#define PLAYER_H

#include <QString>
#include "hand.h"

class Player
{
public:
    Player();
    Player(QString n);
    QString getName();
    void setName(QString n);
    int getScore();
    void setScore(int s);
    Hand& getHand();
    void setHand(Hand h);

private:
    QString name;
    int score;
    Hand hand;
};

#endif // PLAYER_H
