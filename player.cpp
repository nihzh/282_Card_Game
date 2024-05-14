#include "player.h"

Player::Player() :score(0){}

Player::Player(QString n):name(n), score(0) {}

/*
 * getter and setter of private attributes
 */
QString Player::getName(){
    return name;
}

void Player::setName(QString n){
    name = n;
}

int Player::getScore(){
    return score;
}

void Player::setScore(int s){
    score = s;
}

Hand& Player::getHand(){
    return hand;
}

void Player::setHand(Hand h){
    hand = h;
}
