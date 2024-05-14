#include "deck.h"
#include <QRandomGenerator>

Deck::Deck() {}

void Deck::createDeck(){
    // creates 52 cards pack
    for (int i = 1; i <= 4; ++i){
        for (int j = 1; j <= 13; ++j){
            cards.append(Card(i, j));
        }
    }
}

void Deck::shuffle(){
    // use std::random_shuffle to shuffle the cards
    std::srand(unsigned(time(0)));
    std::random_shuffle(cards.begin(), cards.end());
}

// get a card from the first
Card Deck::dealCard(){
    Card firstCard = cards.first();
    cards.removeFirst();
    return firstCard;
}

// return now many cars left
int Deck::getRest(){
    return cards.size();
}

Card Deck::swapCard(Card oldCard){
    // get a random index to replace
    int randomIndex = QRandomGenerator::global()->bounded(cards.size() - 1);
    Card newCard = cards[randomIndex];
    cards[randomIndex] = oldCard;
    return newCard;
}
