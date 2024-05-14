#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include <QObject>
#include <QGroupBox>
#include <QPushButton>
#include <QFrame>
#include <QLabel>
#include <QPixmap>
#include <QMessageBox>
#include <QRegularExpression>
#include "game.h"

class GameController : public QObject
{
    Q_OBJECT;

public:
    GameController(QLabel* lblRest, QLabel* lblRound, QLabel* lblUser,  QLabel* lblRobot, QLabel* lblWinner,
                   QGroupBox* gpbUserHand, QGroupBox* gpbRobotHand,
                   QPushButton* btnStart, QPushButton* btnNextRound, QPushButton* btnSwap, QPushButton* btnConfirm, QPushButton* btnGameOver,
                   QString username, QObject* parent = nullptr)
                : QObject(parent),
                lblRest(lblRest),
                lblRound(lblRound),
                lblUserScore(lblUser),
                lblRobotScore(lblRobot),
                lblWinner(lblWinner),
                gpbUserHand(gpbUserHand),
                gpbRobotHand(gpbRobotHand),
                btnStart(btnStart),
                btnNextRound(btnNextRound),
                btnSwap(btnSwap),
                btnConfirm(btnConfirm),
                btnGameOver(btnGameOver){
        if (username != "")
            theGame = new Game(username);
        else
            theGame = new Game();
        connect(btnStart, &QPushButton::clicked, this, &GameController::gameStart);
        connect(btnNextRound, &QPushButton::clicked, this, &GameController::nextRound);
        connect(btnGameOver, &QPushButton::clicked, this, &GameController::gameOver);
        connect(btnSwap, &QPushButton::clicked, this, &GameController::swap);
        connect(btnConfirm, &QPushButton::clicked, this, &GameController::swapConfirm);
    }

    ~GameController(){
        delete theGame;
    }

    void refreshDisplay(){
        // user hand display
        // get category display, will also sort the cards to the best
        QString userCategory = theGame->getUser().getHand().getCategory();
        gpbUserHand->findChild<QLabel*>("labelUserCategory")->setText(userCategory);

        // get sorted hand, output
        QVector<Card> userHand = theGame->getUser().getHand().getCards();
        for (int i = 0; i < 5; ++i){
            // get widgets
            QPushButton* cardImage = gpbUserHand->findChild<QPushButton*>("pushButtonUserCard" + QString::number(i+1));
            QLabel* cardName = gpbUserHand->findChild<QLabel*>("labelUserCard" + QString::number(i+1));

            // card image path, set icon
            QString imagePath = ":/images/PNG-cards-1.3/" + userHand[i].getImagePath();
            QIcon icon(imagePath);
            if (!icon.isNull()){
                cardImage->setIcon(icon);
                // set card name
                cardName->setText(userHand[i].getName());
            }
        }


        // robot hand display
        // get category display, will also sort the cards to the best
        QString robotCategory = theGame->getRobot().getHand().getCategory();
        gpbRobotHand->findChild<QLabel*>("labelRobotCategory")->setText(robotCategory);

        // get sorted hand, output
        QVector<Card>robotHand = theGame->getRobot().getHand().getCards();
        for (int i = 0; i < 5; ++i){
            // get widgets
            QPushButton* cardImage = gpbRobotHand->findChild<QPushButton*>("pushButtonRobotCard" + QString::number(i+1));
            QLabel* cardName = gpbRobotHand->findChild<QLabel*>("labelRobotCard" + QString::number(i+1));

            // card image path, set icon
            QString imagePath = ":/images/PNG-cards-1.3/" + robotHand[i].getImagePath();
            QIcon icon(imagePath);
            if (!icon.isNull()){
                cardImage->setIcon(icon);
                // set card name
                cardName->setText(robotHand[i].getName());
            }
        }

        // set info value
        lblRound->setText(QString::number(this->theGame->getRound()));
        lblUserScore->setText(QString::number(this->theGame->getUser().getScore()));
        lblRobotScore->setText(QString::number(this->theGame->getRobot().getScore()));
        lblRest->setText(QString::number(this->theGame->getDeck().getRest()));

        // set winner
        QString winnerInfo = "";
        // depend on comparation
        switch(this->theGame->compareHands()){
            case 1:
                winnerInfo = QString(this->theGame->getUser().getName() + " Winning!");
                break;
            case -1:
                winnerInfo = QString(this->theGame->getRobot().getName() + " Winning!");
                break;
            case 0:
                winnerInfo = QString("Draw!");
                break;
            default:
                break;
        }
        lblWinner->setText(winnerInfo);
    }

    void newRound(){
        // roundStart will return a signal if round reached more than 5
        if(!this->theGame->roundStart()){
            gameOverDialog();
        }

        // cannot swap in round 5
        if (this->theGame->getRound() == 5){
            // disable the swap button
            btnSwap->setEnabled(false);
        }
        else {
            // enable the swap button
            btnSwap->setEnabled(true);
        }

        // QVector<int> robotHand = {211, 311, 203, 403, 213};
        // this->theGame->getRobot().getHand().setHand(robotHand);
        // QVector<int> userHand = {211, 311, 203, 403, 201};
        // this->theGame->getUser().getHand().setHand(userHand);
        refreshDisplay();
    }

    // summary message when game over
    void gameOverDialog(){
        // get scores
        int robotScore = this->theGame->getRobot().getScore();
        int userScore = this->theGame->getUser().getScore();
        // set message on score
        QString message = "Robot's score: " + QString::number(robotScore) + "\nYour score: " + QString::number(userScore) + "\n\n";
        // plus the winner's info
        if (userScore > robotScore)
            message += QString(this->theGame->getUser().getName()) + " Win!";
        else if (userScore < robotScore)
            message += QString(this->theGame->getRobot().getName()) + " Win!";
        else
            message += "Draw!";
        // question messagebox, yes for start a new game
        int result = QMessageBox::question(nullptr, "Game Over!", message + "\n\nDo you want to play again?");
        if (result == QMessageBox::Yes){
            gameStart();
        }
    }

    // set username, call by slot function of CardGameMain
    void setUsername(QString username){
        this->theGame->getUser().setName(username);
    }

// use public slot, the CardGameMain class's slot funciton need to call this function
public slots:
    void gameStart(){
        // new the game object
        if (theGame){
            delete theGame;
        }
        theGame = new Game();

        // set button visible
        btnNextRound->show();
        btnGameOver->hide();

        // the start button cannot be clicked when started
        //btnStart->setEnabled(false);
        // enable other buttons
        btnSwap->setEnabled(true);
        btnNextRound->setEnabled(true);
        btnGameOver->setEnabled(true);
        btnConfirm->setEnabled(true);

        // shuffle the card
        theGame->getDeck().shuffle();

        // start a new round
        newRound();
    }

private slots:
    void nextRound(){
        // do roundEnd (calculate score)
        this->theGame->roundEnd();
        // if going to final round, change the button
        if (this->theGame->getRound() == 4){
            // set button visible
            btnNextRound->hide();
            btnGameOver->show();
        }
        // goto next round
        newRound();
    }

    void gameOver(){
        // do roundEnd (calculate the final score)
        this->theGame->roundEnd();
        refreshDisplay();
        btnSwap->setEnabled(false);
        btnNextRound->setEnabled(false);
        btnGameOver->setEnabled(false);
        gameOverDialog();
    }

    void swap(){
        // change button
        btnSwap->hide();
        btnConfirm->show();
        // find card buttons, connect slot for each
        //QVector<QPushButton*> cardButtons = gpbUserHand->findChildren<QPushButton*>();
        QVector<QPushButton*> cardButtons = gpbUserHand->findChildren<QPushButton*>(QRegularExpression("^pushButtonUserCard"));
        foreach(QPushButton* eachButton, cardButtons){
            connect(eachButton, &QPushButton::clicked, this, &GameController::swapSelect);
            eachButton->setCheckable(true);
        }
    }

    // select swap card, send to swapList of the game
    void swapSelect(){
        // use sender(), get the button cliced
        QPushButton *button = qobject_cast<QPushButton *>(sender());
        // get the name of the button
        QString buttonName = button->objectName();
        // cut final character, change to int (will be the index 1-5)
        int buttonIndex = buttonName.back().digitValue();
        if (buttonIndex != -1){
            // add the index to swapList
            this->theGame->addSwap(buttonIndex);
            // if(button->isChecked())
            //     button->setChecked(false);
            // else
            //     button->setChecked(true);
        }
    }

    // click the button "confirm" to confirm the swaping
    void swapConfirm(){
        // change button
        btnSwap->show();
        btnConfirm->hide();
        // find card buttons, remove slot for each
        QVector<QPushButton*> cardButtons = gpbUserHand->findChildren<QPushButton*>(QRegularExpression("^pushButtonUserCard"));
        foreach(QPushButton* eachButton, cardButtons){
            // remove listener
            disconnect(eachButton, &QPushButton::clicked, this, &GameController::swapSelect);
            // disable check and checkable
            eachButton->setChecked(false);
            eachButton->setCheckable(false);
        }
        this->theGame->swapCards();
        // if swaped 3 cards, enable the swap button
        if (this->theGame->getUser().getHand().getSwapSpare() == 0){
            btnSwap->setEnabled(false);
        }
        // refresh the display after swaping
        refreshDisplay();
    }


private:
    QLabel* lblRest;
    QLabel* lblRound;
    QLabel* lblUserScore;
    QLabel* lblRobotScore;
    QLabel* lblWinner;
    QGroupBox* gpbUserHand;
    QGroupBox* gpbRobotHand;
    QPushButton* btnStart;
    QPushButton* btnNextRound;
    QPushButton* btnSwap;
    QPushButton* btnConfirm;
    QPushButton* btnGameOver;
    Game* theGame;
};

#endif // GAMECONTROLLER_H
