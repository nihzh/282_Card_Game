#ifndef DECK_H
#define DECK_H

#include <QVector>
#include "card.h"

class Deck
{
public:
    Deck();
    void createDeck();
    void shuffle();
    Card dealCard();

    int getRest();
    Card swapCard(Card oldCard);

private:
    QVector<Card> cards;
};

#endif // DECK_H
