#include "cardgamemain.h"
#include "ui_cardgamemain.h"
#include <QInputDialog>

CardGameMain::CardGameMain(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::CardGameMain)
{
    ui->setupUi(this);


    // card deck image: rotate 90 degrees, scale and set to label
    QPixmap pixmap(":/images/PNG-cards-1.3/back");
    // rotate
    QTransform trans;
    trans.rotate(90);
    pixmap = pixmap.transformed(trans);
    // scale
    QSize size(131, 91);
    pixmap = pixmap.scaled(size, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    // set pixmap
    ui->labelCardDeck->setPixmap(pixmap);

    // set button visible
    ui->pushButtonNextRound->show();
    ui->pushButtonGameOver->hide();
    ui->pushButtonSwap->show();
    ui->pushButtonConfirm->hide();

    // enable start button and disable others
    //ui->pushButtonStartGame->setEnabled(true);
    ui->pushButtonSwap->setEnabled(false);
    ui->pushButtonNextRound->setEnabled(false);
    ui->pushButtonGameOver->setEnabled(false);
    ui->pushButtonConfirm->setEnabled(false);

    // slot: reset game button (menubar)
    connect(ui->actionReset_Game, &QAction::triggered, this, &CardGameMain::reInitialize);

    // slot: set player name button (menubar)
    connect(ui->actionSet_Player_s_name, &QAction::triggered, this, &CardGameMain::setPlayer);

    // slot: about me (menubar)
    connect(ui->actionAbout_me, &QAction::triggered, this, &CardGameMain::aboutMe);

    initializeGame();
}

CardGameMain::~CardGameMain()
{
    delete ui;
}

// call when restart the game, delete the previous
void CardGameMain::reInitialize(){
    delete controller;
    initializeGame();
    // start directly
    controller->gameStart();
}

void CardGameMain::setPlayer(){
    // get username from InputDialog
    QString uname = QInputDialog::getText(this, "Set Player Name", "Your name: ", QLineEdit::Normal, "", nullptr);
    this->username = uname;
    // set to controller if initialized
    if (controller){
        controller->setUsername(uname);
    }
    // set ui
    ui->labelUserScoreText->setText(uname + ": ");
    ui->groupBoxUserHand->setTitle(uname + "'s Hand");
}

void CardGameMain::aboutMe(){
    QMessageBox::information(nullptr, "About me", "Author's name: Jingfan Zhou\nStudent No.(UoL): 201737077\nLast edit: 13 May, 2024\nMy blog: nihzh.github.io");
}

void CardGameMain::initializeGame(){
    // new a game controller
    controller = new GameController(ui->labelCardRest, ui->labelRound, ui->labelUserScore, ui->labelRobotScore, ui->labelWinner,
                       ui->groupBoxUserHand, ui->groupBoxRobotHand,
                       ui->pushButtonStartGame, ui->pushButtonNextRound, ui->pushButtonSwap, ui->pushButtonConfirm, ui->pushButtonGameOver,
                       username, this);
}
