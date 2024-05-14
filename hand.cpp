#include "hand.h"
#include <algorithm>

Hand::Hand() {}

void Hand::dealHand(Deck& deck){
    // first clear the hand
    hand.clear();
    // dealCard 5 tiems
    for (int i = 0; i < 5; ++i){
        hand.append(deck.dealCard());
    }
    // initialize swap counter
    swapCount = 0;
}

void Hand::sortValue(){
    //std::sort(hand.begin(), hand.end())
    bool isStraight = this->isStraight();
    // a mark for ace straight, for exclusive process
    bool hasAceStraight = false;
    // selection sort: select smallest index and put to start
    for (int i = 0; i < 5; ++i){
        int smallestIndex = i;
        for (int j = i; j < 5; ++j){
            // the getValue of Card always return 1 as 14
            // is part of straight Ace, get smallest index and break
            if ((isStraight && hand[j].getValue() == 14)){
                // found Ace and is straight, mark and process later
                hasAceStraight = true;
                continue;
            }
            // smaller than smallest one, change smallest index
            if (hand[j].getValue() < hand[smallestIndex].getValue()){
                smallestIndex = j;
            }
        }
        // swap
        Card tmp = hand[smallestIndex];
        hand[smallestIndex] = hand[i];
        hand[i] = tmp;
    }

    // the Ace is already be seen as 14
    // if has ace and straight, if 2 includes, seen as 1
    if (hasAceStraight){
        bool has2 = false;
        for (int i = 0; i < 5; ++i){
            if (hand[i].getValue() == 2)
                has2 = true;
        }
        // take from last and insert to first
        if (has2){
            Card one = hand.last();
            hand.removeLast();
            hand.insert(0, one);
        }
    }
}

void Hand::sortGroup(){
    // get value count
    QMap<int, int> valueCount = this->getValueCount();
    // swaping when not complete
    while (!valueCount.empty()){
        // get minimum count
        int minValue = valueCount.firstKey();
        int minCount = valueCount.first();
        // use iterator, find smaller count
        for (auto it = valueCount.begin(); it != valueCount.end(); ++it){
            if (it.value() < minCount){
                minValue = it.key();
                minCount = it.value();
            }
        }

        // put all minimum to the beginning
        while(minCount > 0){
            // find from end to start
            for (int i = 4; i >= 0; --i){
                // is the min
                if (hand[i].getValue() == minValue){
                    // get the element
                    Card tmp = hand[i];
                    // remove from origin index
                    hand.remove(i);
                    // insert to first
                    hand.insert(0, tmp);
                    minCount--;
                    break;
                }
            }
        }

        // remove the minimum pair
        valueCount.remove(minValue);
    }
}

// this method will also sort the cards to the best combo
QString Hand::getBest(){
    // sort value at first
    this->sortValue();

    //determine 3 easy and exclusive type at first
    bool isStraight = this->isStraight();
    bool isFlush = this->isFlush();
    // Straight Flush
    if (isFlush && isStraight){
        return QString("stfl");
    }
    // Flush
    if (isFlush){
        return QString("flsh");
    }
    // Straight
    if (isStraight){
        return QString("strt");
    }

    // sort the cards as group
    this->sortGroup();
    QMap<int, int> valueCount = this->getValueCount();
    // distinguish category by number of different card values
    switch(valueCount.size()){
        // two different values, four or full
        case 2:
            // determine by card value count of each, four is 4; full is 2 or 3
            if (findMaxCount(valueCount) == 4){
                return QString("four");
            }
            else{
                return QString("full");
            }
        // three different values, trio or twop
        case 3:
            // determine by card count value of each, trio is 3, twop is 2
            if (findMaxCount(valueCount) == 3){
                return QString("trio");
            }
            else{
                return QString("twop");
            }
        // four different values, pair
        case 4:
            return QString("pair");
        // no same card value, high
        default:
            return QString("high");
    }
}

// find the max count(value of the pair) from valueCount QMap
int Hand::findMaxCount(QMap<int, int> valueCount){
    int maxCount = 0;
    for (auto it = valueCount.begin(); it != valueCount.end(); ++it){
        if (it.value() > maxCount)
            maxCount = it.value();
    }
    return maxCount;
}

// return the rank category number of the best possible
QVector<Card> Hand::getCards(){
    return hand;
}

void Hand::setHand(const QVector<int>& cardValues){
    // remove all elements from hand
    hand.clear();
    // insert cards
    for (auto it = cardValues.begin(); it != cardValues.end(); ++it){
        // hundred digit
        int suit = (int)(*it / 100);
        // ten and one digit
        int value = *it % 100;
        hand.append(Card(suit, value));
    }
}
void Hand::swapCard(const QVector<int> cardIndices, Deck& deck){
    // record swaped index to prevent duplicated
    QVector<int> swaped;
    // prevent size more than 3
    int swapSpare = this->getSwapSpare();
    int i = 0;
    // might skip when duplicated, so use while to make sure reach the count
    while (i < swapSpare && i < cardIndices.count()){
        // only process not duplicated
        if (!swaped.contains(cardIndices[i])){
            // for each given indice, put old card back and get a new from the deck
            Card oldCard = hand[cardIndices[i] - 1];
            hand[cardIndices[i] - 1] = deck.swapCard(oldCard);
            swapCount++;
            // add to swaped
            swaped.append(cardIndices[i]);
        }
        ++i;
    }
}

// wheather the current hand is a straight
bool Hand::isStraight(){
    // First get minimum value as target
    // initial as a largest value
    int targValue = 17;
    // for 5 cards in hand
    for (int i = 0; i < 5; ++i){
        // found the A, calculate as 1 when use in straight and stop finding
        if (hand[i].getValue() == 14){
            targValue = 1;
            break;
        }
        // find a smaller value
        if (hand[i].getValue() < targValue){
            targValue = hand[i].getValue();
        }
    }
    // find fron the second
    targValue += 1;

    // if Ace exists in hand, find both possible
    if (targValue == 2){
        return count5FromMin(2) || count5FromMin(11);
    }

    // find if cards are continuous
    return count5FromMin(targValue);
}

// from minimum value startValue, increasing count 4 times and looing for existing, which can determine a straight
bool Hand::count5FromMin(int startValue){
    // count 5 from the minimum value, find rests are continuous
    for (int i = 0; i < 4; ++i){
        // the start value must contain in the hand's card value
        bool hasThis = std::any_of(hand.begin(), hand.end(), [startValue](Card &eachCard) {
            return eachCard.getValue() == startValue;
        });
        // no this value
        if (!hasThis){
            return false;
        }
        startValue += 1;
    }
    return true;
}

// wheather the current hand is a flush
bool Hand::isFlush(){
    int suit = hand[0].getSuitNum();
    // find all 5 cards
    for (int i = 1; i < 5; ++i){
        // one of these not same, return false
        if(hand[i].getSuitNum() != suit)
            return false;
    }
    // all same suit
    return true;
}

// return the spare times of swap
int Hand::getSwapSpare(){
    return 3 - swapCount;
}

// return a value count map of current hand, key: the value of cards; value: count
QMap<int, int> Hand::getValueCount(){
    QMap<int, int> valueCount;
    for (int i = 0; i < 5; ++i){
        // the value appeared
        if(valueCount.contains(hand[i].getValue())){
            // plus num
            valueCount[hand[i].getValue()]++;
        }
        else{
            // set num to 1
            valueCount.insert(hand[i].getValue(), 1);
        }
    }
    return valueCount;
}

// return the discription of the hand category and ranking
QString Hand::getCategory(){
    const QVector<QString> rankList = {"stfl", "four", "full", "flsh", "strt", "trio", "twop", "pair", "high"};
    QString best = this->getBest();
    int rank = rankList.indexOf(best) + 1;
    if (best == "stfl"){
        return QString("Straight Flush! With highest " + hand.last().getValueStr() + ". Ranked: " + QString::number(rank) + "!");
    }
    if (best == "four"){
        return QString("Four of value " + hand.first().getValueStr() + "! Ranked: " + QString::number(rank) + "!");
    }
    if (best == "full"){
        return QString("Full House of value " + hand.first().getValueStr() + "! Ranked: " + QString::number(rank) + "!");
    }
    if (best == "flsh"){
        return QString("Flush! With highest " + hand.last().getValueStr() + ". Ranked: " + QString::number(rank) + "!");
    }
    if (best == "strt"){
        return QString("Straight! With highest " + hand.last().getValueStr() + ". Ranked: " + QString::number(rank) + ".");
    }
    if (best == "trio"){
        return QString("Three of value " + hand.first().getValueStr() + "! Ranked: " + QString::number(rank) + ".");
    }
    if (best == "twop"){
        return QString("Two pairs with highest " + hand.first().getValueStr() + ". Ranked: " + QString::number(rank) + ".");
    }
    if (best == "pair"){
        return QString("One pair of value " + hand.first().getValueStr() + ". Ranked: " + QString::number(rank) + ".");
    }
    if (best == "high"){
        return QString("Highest value: " + hand.first().getValueStr() + ". Ranked: " + QString::number(rank) + ".");
    }
    return QString("best calculate error");
}
