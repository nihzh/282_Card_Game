#ifndef GAME_H
#define GAME_H

#include "player.h"
#include "deck.h"

class Game
{

public:
    Game();
    Game(QString n);
    Player& getRobot();
    void setRobot(Player p);
    Player& getUser();
    void setUser(Player p);
    Deck& getDeck();
    void setDeck(Deck deck);

    void dealCards();
    int compareHands();
    int getRound();
    bool roundStart();
    void roundEnd();
    void swapCards();
    void addSwap(int index);
    void removeSwap(int index);

private:
    Player robot;
    Player user;
    Deck deck;
    int round;
    QVector<int> swapList;
};

#endif // GAME_H
