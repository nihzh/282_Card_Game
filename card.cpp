#include "card.h"

Card::Card() {}

Card::Card(int s, int v):suit(s), value(v){}

Card::Card(QString s, int v):value(v){
    // user set method to deal with conversion from QString to int
    setSuit(s);
}

int Card::getValue(){
    if (value == 1){
        return 14;
    }
    return value;
}

void Card::setValue(int v){
    value = v;
}

// return string of the value
QString Card::getValueStr(){
    switch(value){
    case 1:
        return "Ace";
    case 2:
        return "Two";
    case 3:
        return "Three";
    case 4:
        return "Four";
    case 5:
        return "Five";
    case 6:
        return "Six";
    case 7:
        return "Seven";
    case 8:
        return "Eight";
    case 9:
        return "Nine";
    case 10:
        return "Ten";
    case 11:
        return "Jack";
    case 12:
        return "Queen";
    case 13:
        return "King";
    default:
        return "value error";
    }
}

QString Card::getSuit(){
    if (suit == 1){
        return QString("Clubs");
    }
    else if (suit == 2){
        return QString("Diamonds");
    }
    else if (suit == 3){
        return QString("Hearts");
    }
    else if (suit == 4){
        return QString("Spades");
    }
    return QString("type error");
}

int Card::getSuitNum(){
    return suit;
}

// return suit
void Card::setSuit(QString s){
    if (s == "club"){
        suit = 1;
    }
    else if (s == "diamond"){
        suit = 2;
    }
    else if (s == "heart"){
        suit = 3;
    }
    else if (s == "space"){
        suit = 4;
    }
    else{
        suit = 0;
    }
}

QString Card::getName(){
    return this->getValueStr() + " of " + this->getSuit();
}

int Card::getNumber(){
    return suit * 100 + value;
}

QString Card::getImagePath(){
    // process the special case of the value
    QString value;
    switch(this->value){
    case 1:
        value = "ace";
        break;
    case 11:
        value = "jack";
        break;
    case 12:
        value = "queen";
        break;
    case 13:
        value = "king";
        break;
    default:
        value = QString::number(this->value);
    }
    // combine with the format, get the suit name and to lower case
    return QString("%1_of_%2.png").arg(value).arg(this->getSuit().toLower());
}
