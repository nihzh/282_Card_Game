#ifndef HAND_H
#define HAND_H

#include <QMap>
#include "card.h"
#include "deck.h"

class Hand
{
public:
    Hand();
    void dealHand(Deck& deck);
    void sortValue();
    void sortGroup();
    QString getBest();
    void setHand(const QVector<int>& cardValues);
    void swapCard(const QVector<int> cardIndices, Deck& deck);

    bool isStraight();
    bool isFlush();
    QVector<Card> getCards();
    int getSwapSpare();
    QMap<int, int> getValueCount();
    QString getCategory();
    int findMaxCount(QMap<int, int> valueCount);
    bool count5FromMin(int startValue);

private:
    QVector<Card> hand;
    int swapCount;
};

#endif // HAND_H
