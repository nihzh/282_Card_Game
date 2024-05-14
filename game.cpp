#include "game.h"

Game::Game() {
    robot = Player("Robot");
    user = Player("new player");
    deck = Deck();
    deck.createDeck();
    round = 0;
}

Game::Game(QString n){
    robot = Player("Robot");
    user = Player(n);
    deck = Deck();
    deck.createDeck();
    round = 0;
}

/*
 * getter and setter of three players
*/
Player& Game::getRobot(){
    return robot;
}

void Game::setRobot(Player p){
    robot = p;
}

Player& Game::getUser(){
    return user;
}

void Game::setUser(Player p){
    user = p;
}

Deck& Game::getDeck(){
    return deck;
}

void Game::setDeck(Deck deck){
    this->deck = deck;
}

int Game::getRound(){
    return round;
}

// call when beginning of each round, deal cards for two players
void Game::dealCards(){
    robot.getHand().dealHand(deck);
    user.getHand().dealHand(deck);
}

// compare two values, if a greater than b returns 1, returns -1 when opposite, 0 when same
int compareValue(int a, int b){
    if (a > b)
        return 1;
    else if (a < b)
        return -1;
    return 0;
}

// return: 1 as user win, -1 as robot win, 0 as draw
// first comapre category, if draw, then compare each cards depend on different categories and rules
int Game::compareHands(){
    // first, compare category
    const QVector<QString> rankList = {"stfl", "four", "full", "flsh", "strt", "trio", "twop", "pair", "high"};
    // get rank level by index of the category rank list
    int userRank = rankList.indexOf(user.getHand().getBest()) + 1;  // plus one which compatible with rank table in the requirement
    int robotRank = rankList.indexOf(robot.getHand().getBest()) + 1;
    // compare category rank, smaller better
    if (userRank < robotRank){
        return 1;
    }
    else if (userRank > robotRank){
        return -1;
    }

    // same category, compare card value
    QVector<Card> userHand = user.getHand().getCards();
    QVector<Card> robotHand = robot.getHand().getCards();

    // high, need to compare all cards
    if (userRank == 9){
        for (int i = 0; i < 5; ++i){
            int result = compareValue(userHand[i].getValue(), robotHand[i].getValue());
            // if peer card values same
            if (result == 0){
                // all card values same, draw
                if (i == 4)
                    return 0;
                // find next peer
                continue;
            }
            // not same, return result
            return result;
        }
    }

    // flsh, compare all cards, from end to start
    if (userRank == 4){
        for (int i = 4; i >= 0; --i){
            int result = compareValue(userHand[i].getValue(), robotHand[i].getValue());
            // if peer card values same
            if (result == 0){
                // all card values same, draw
                if (i == 0)
                    return 0;
                // find next peer
                continue;
            }
            // not same, return result
            return result;
        }
    }

    int userHighest = 0;
    int robotHighest = 0;
    // stfl or strt, ranked as value, compare the final one as the highest (useless condition, but required)
    if (userRank == 1 || userRank == 5){
        userHighest = userHand.last().getValue();
        robotHighest = robotHand.last().getValue();
    }
    // other categories, ranked as group, compare the first one as the highest
    else{
        userHighest = userHand.first().getValue();
        robotHighest = robotHand.first().getValue();
    }

    // get result of highest value
    int firstResult = compareValue(userHighest, robotHighest);

    // twop or pair, need next step if first pare are same
    if (firstResult == 0){
        if (userRank == 7){
            // first pair same, compare second pare (the 3rd card)
            int secondResult = compareValue(userHand[2].getValue(), robotHand[2].getValue());
            // second pare still same, compare the single card (the last one)
            if (secondResult == 0)
                return compareValue(userHand.last().getValue(), robotHand.last().getValue());
            // second pare not same, return the result
            return secondResult;
        }
        if (userRank == 8){
            // first pair same, compare highest single card (the last one)
            return compareValue(userHand.last().getValue(), robotHand.last().getValue());
        }
    }

    // other categories
    return firstResult;
}

// return the stage of starting a new round, return false when round 5
bool Game::roundStart(){
    if (round == 5){
        return false;
    }
    // plus round
    this->round += 1;
    // deal cards for two users
    dealCards();
    return true;
}

void Game::roundEnd(){
    switch(compareHands()){
    case 1:
        user.setScore(user.getScore() + 1);
        break;
    case -1:
        robot.setScore(robot.getScore() + 1);
        break;
    default:
        break;
    }
}

void Game::swapCards(){
    // get robot swap times
    int robotSwapCount = swapList.count();

    // user swap depend on the swap list
    user.getHand().swapCard(swapList, deck);
    swapList.clear();

    // user still winning after the user swaped, robot no swap
    if (compareHands() == -1){
        return;
    }


    // robot decide swap
    // swap one card each time, no more than robotSwapCount times
    for (int i = 0; i < robotSwapCount; ++i){
        QString robotBest = robot.getHand().getBest();
        // no need to swap for straight, four, full, flush and straight

        // for trio and twop, get the highest single card, swap the minimun single (number 5)
        if (robotBest == "trio" || robotBest == "twop" || robotBest == "high"){
            QVector<int> robotSwap = {5};
            robot.getHand().swapCard(robotSwap, deck);
        }

        // pair
        else if (robotBest == "pair"){
            // if can make a straight or a flush by swaping one of the pair, swap one of the pair
            QMap<int, int> valueCount = robot.getHand().getValueCount();
            // initially set swap target to 1 (one of the pair)
            int swapTarg = 1;

            // judge for straight, find distance between max and min value
            bool canStraight = false;
            int minValue = 17;
            int maxValue = 0;
            // find min and max value
            for (int value : valueCount.keys()){
                if (value < minValue)
                    minValue = value;
                if (value > maxValue)
                    maxValue = value;
            }
            int distance = maxValue - minValue;
            // 4: hand include the edge of straight; 3: hand not include the edge of straight
            if (distance == 4 || distance == 3){
                canStraight = true;
            }

            // judge for flush, get suit count
            bool canFlush = false;
            // key: suit num; value: indexs of cards in that suit
            QMap<int, QVector<int>> suitIndex;
            // get robot hand cards
            QVector<Card> robotCards = robot.getHand().getCards();
            for (int i = 0; i < 5; ++i){
                // append index to the value for key is card's suit num
                suitIndex[robotCards[i].getSuitNum()].append(i);
            }
            // only two types of suites, the different must one of the pair
            if (suitIndex.count() == 2){
                canFlush = true;
                // get the index of the different
                QVector<int> firstSuit = suitIndex.first();
                QVector<int> secondSuit = suitIndex.last();
                // get target index from which has only one element
                swapTarg = firstSuit.count() == 1 ? firstSuit.first():secondSuit.first();
            }

            // can make a straight or a flush by swaping one of the pair
            if (canFlush || canStraight){
                QVector<int> robotSwap = {swapTarg};
                robot.getHand().swapCard(robotSwap, deck);
            }
            // else, swap the minimum
            else{
                QVector<int> robotSwap = {5};
                robot.getHand().swapCard(robotSwap, deck);
            }
        }
    }
}

void Game::addSwap(int index){
    // between 1-5 and not contain, add
    if (index <= 5 && index >= 1 && !swapList.contains(index))
        swapList.append(index);
    // already contain, remove
    else if(swapList.contains(index))
        swapList.removeAll(index);
}

void Game::removeSwap(int index){
    // remove all if contain
    if (swapList.contains(index))
        swapList.removeAll(index);
}
