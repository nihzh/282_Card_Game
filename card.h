#ifndef CARD_H
#define CARD_H

#include <QString>

class Card
{
public:
    Card();
    Card(int s, int v);
    Card(QString s, int v);
    int getValue();
    void setValue(int v);
    QString getValueStr();
    QString getSuit();
    int getSuitNum();
    void setSuit(QString s);
    QString getName();
    int getNumber();
    // compose by value and suit, .png
    QString getImagePath();

private:
    int suit;
    int value;
};

#endif // CARD_H
