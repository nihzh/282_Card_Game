/********************************************************************************
** Form generated from reading UI file 'cardgamemain.ui'
**
** Created by: Qt User Interface Compiler version 6.2.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CARDGAMEMAIN_H
#define UI_CARDGAMEMAIN_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CardGameMain
{
public:
    QAction *actionReset_Game;
    QAction *actionSet_Player_s_name;
    QAction *actionAbout_me;
    QWidget *centralwidget;
    QPushButton *pushButtonStartGame;
    QGroupBox *groupBoxUserHand;
    QFrame *frameUserCard1;
    QPushButton *pushButtonUserCard1;
    QLabel *labelUserCard1;
    QLabel *labelUserCard2;
    QFrame *frameUserCard2;
    QPushButton *pushButtonUserCard2;
    QLabel *labelUserCard3;
    QFrame *frameUserCard3;
    QPushButton *pushButtonUserCard3;
    QLabel *labelUserCard4;
    QFrame *frameUserCard4;
    QPushButton *pushButtonUserCard4;
    QLabel *labelUserCard5;
    QFrame *frameUserCard5;
    QPushButton *pushButtonUserCard5;
    QLabel *labelUserCategory;
    QLabel *labelCardRestText;
    QPushButton *pushButtonSwap;
    QGroupBox *groupBoxRobotHand;
    QFrame *frameRobotCard1;
    QPushButton *pushButtonRobotCard1;
    QLabel *labelRobotCard1;
    QLabel *labelRobotCard2;
    QFrame *frameRobotCard2;
    QPushButton *pushButtonRobotCard2;
    QLabel *labelRobotCard3;
    QFrame *frameRobotCard3;
    QPushButton *pushButtonRobotCard3;
    QLabel *labelRobotCard4;
    QFrame *frameRobotCard4;
    QPushButton *pushButtonRobotCard4;
    QLabel *labelRobotCard5;
    QFrame *frameRobotCard5;
    QPushButton *pushButtonRobotCard5;
    QLabel *labelRobotCategory;
    QLabel *labelRoundText;
    QLabel *labelUserScoreText;
    QLabel *labelRobotScoreText;
    QLabel *labelRound;
    QLabel *labelUserScore;
    QLabel *labelRobotScore;
    QLabel *labelCardRest;
    QPushButton *pushButtonNextRound;
    QLabel *labelWinner;
    QLabel *labelCardDeck;
    QPushButton *pushButtonGameOver;
    QPushButton *pushButtonConfirm;
    QMenuBar *menubar;
    QMenu *menuReset_Game;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *CardGameMain)
    {
        if (CardGameMain->objectName().isEmpty())
            CardGameMain->setObjectName(QString::fromUtf8("CardGameMain"));
        CardGameMain->resize(933, 741);
        QFont font;
        font.setFamilies({QString::fromUtf8("Consolas")});
        font.setPointSize(11);
        CardGameMain->setFont(font);
        actionReset_Game = new QAction(CardGameMain);
        actionReset_Game->setObjectName(QString::fromUtf8("actionReset_Game"));
        actionSet_Player_s_name = new QAction(CardGameMain);
        actionSet_Player_s_name->setObjectName(QString::fromUtf8("actionSet_Player_s_name"));
        actionAbout_me = new QAction(CardGameMain);
        actionAbout_me->setObjectName(QString::fromUtf8("actionAbout_me"));
        centralwidget = new QWidget(CardGameMain);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        pushButtonStartGame = new QPushButton(centralwidget);
        pushButtonStartGame->setObjectName(QString::fromUtf8("pushButtonStartGame"));
        pushButtonStartGame->setGeometry(QRect(70, 310, 121, 71));
        pushButtonStartGame->setContextMenuPolicy(Qt::NoContextMenu);
        groupBoxUserHand = new QGroupBox(centralwidget);
        groupBoxUserHand->setObjectName(QString::fromUtf8("groupBoxUserHand"));
        groupBoxUserHand->setGeometry(QRect(50, 400, 831, 271));
        frameUserCard1 = new QFrame(groupBoxUserHand);
        frameUserCard1->setObjectName(QString::fromUtf8("frameUserCard1"));
        frameUserCard1->setGeometry(QRect(30, 50, 131, 171));
        frameUserCard1->setFrameShape(QFrame::StyledPanel);
        frameUserCard1->setFrameShadow(QFrame::Raised);
        pushButtonUserCard1 = new QPushButton(frameUserCard1);
        pushButtonUserCard1->setObjectName(QString::fromUtf8("pushButtonUserCard1"));
        pushButtonUserCard1->setGeometry(QRect(0, 0, 131, 171));
        pushButtonUserCard1->setIconSize(QSize(131, 165));
        pushButtonUserCard1->setCheckable(false);
        labelUserCard1 = new QLabel(groupBoxUserHand);
        labelUserCard1->setObjectName(QString::fromUtf8("labelUserCard1"));
        labelUserCard1->setGeometry(QRect(30, 220, 141, 31));
        labelUserCard1->setAlignment(Qt::AlignCenter);
        labelUserCard2 = new QLabel(groupBoxUserHand);
        labelUserCard2->setObjectName(QString::fromUtf8("labelUserCard2"));
        labelUserCard2->setGeometry(QRect(190, 220, 141, 31));
        labelUserCard2->setAlignment(Qt::AlignCenter);
        frameUserCard2 = new QFrame(groupBoxUserHand);
        frameUserCard2->setObjectName(QString::fromUtf8("frameUserCard2"));
        frameUserCard2->setGeometry(QRect(190, 50, 131, 171));
        frameUserCard2->setFrameShape(QFrame::StyledPanel);
        frameUserCard2->setFrameShadow(QFrame::Raised);
        pushButtonUserCard2 = new QPushButton(frameUserCard2);
        pushButtonUserCard2->setObjectName(QString::fromUtf8("pushButtonUserCard2"));
        pushButtonUserCard2->setGeometry(QRect(0, 0, 131, 171));
        pushButtonUserCard2->setIconSize(QSize(131, 165));
        pushButtonUserCard2->setCheckable(false);
        labelUserCard3 = new QLabel(groupBoxUserHand);
        labelUserCard3->setObjectName(QString::fromUtf8("labelUserCard3"));
        labelUserCard3->setGeometry(QRect(350, 220, 141, 31));
        labelUserCard3->setAlignment(Qt::AlignCenter);
        frameUserCard3 = new QFrame(groupBoxUserHand);
        frameUserCard3->setObjectName(QString::fromUtf8("frameUserCard3"));
        frameUserCard3->setGeometry(QRect(350, 50, 131, 171));
        frameUserCard3->setFrameShape(QFrame::StyledPanel);
        frameUserCard3->setFrameShadow(QFrame::Raised);
        pushButtonUserCard3 = new QPushButton(frameUserCard3);
        pushButtonUserCard3->setObjectName(QString::fromUtf8("pushButtonUserCard3"));
        pushButtonUserCard3->setGeometry(QRect(0, 0, 131, 171));
        pushButtonUserCard3->setIconSize(QSize(131, 165));
        pushButtonUserCard3->setCheckable(false);
        labelUserCard4 = new QLabel(groupBoxUserHand);
        labelUserCard4->setObjectName(QString::fromUtf8("labelUserCard4"));
        labelUserCard4->setGeometry(QRect(510, 220, 141, 31));
        labelUserCard4->setFont(font);
        labelUserCard4->setAlignment(Qt::AlignCenter);
        frameUserCard4 = new QFrame(groupBoxUserHand);
        frameUserCard4->setObjectName(QString::fromUtf8("frameUserCard4"));
        frameUserCard4->setGeometry(QRect(510, 50, 131, 171));
        frameUserCard4->setFrameShape(QFrame::StyledPanel);
        frameUserCard4->setFrameShadow(QFrame::Raised);
        pushButtonUserCard4 = new QPushButton(frameUserCard4);
        pushButtonUserCard4->setObjectName(QString::fromUtf8("pushButtonUserCard4"));
        pushButtonUserCard4->setGeometry(QRect(0, 0, 131, 171));
        pushButtonUserCard4->setIconSize(QSize(131, 165));
        pushButtonUserCard4->setCheckable(false);
        labelUserCard5 = new QLabel(groupBoxUserHand);
        labelUserCard5->setObjectName(QString::fromUtf8("labelUserCard5"));
        labelUserCard5->setGeometry(QRect(670, 220, 141, 31));
        labelUserCard5->setFont(font);
        labelUserCard5->setAlignment(Qt::AlignCenter);
        frameUserCard5 = new QFrame(groupBoxUserHand);
        frameUserCard5->setObjectName(QString::fromUtf8("frameUserCard5"));
        frameUserCard5->setGeometry(QRect(670, 50, 131, 171));
        frameUserCard5->setFrameShape(QFrame::StyledPanel);
        frameUserCard5->setFrameShadow(QFrame::Raised);
        pushButtonUserCard5 = new QPushButton(frameUserCard5);
        pushButtonUserCard5->setObjectName(QString::fromUtf8("pushButtonUserCard5"));
        pushButtonUserCard5->setGeometry(QRect(0, 0, 131, 171));
        pushButtonUserCard5->setIconSize(QSize(131, 165));
        pushButtonUserCard5->setCheckable(false);
        labelUserCategory = new QLabel(groupBoxUserHand);
        labelUserCategory->setObjectName(QString::fromUtf8("labelUserCategory"));
        labelUserCategory->setGeometry(QRect(220, 10, 391, 41));
        labelUserCategory->setAlignment(Qt::AlignCenter);
        labelCardRestText = new QLabel(centralwidget);
        labelCardRestText->setObjectName(QString::fromUtf8("labelCardRestText"));
        labelCardRestText->setGeometry(QRect(620, 300, 61, 41));
        pushButtonSwap = new QPushButton(centralwidget);
        pushButtonSwap->setObjectName(QString::fromUtf8("pushButtonSwap"));
        pushButtonSwap->setGeometry(QRect(620, 350, 101, 41));
        pushButtonSwap->setContextMenuPolicy(Qt::NoContextMenu);
        groupBoxRobotHand = new QGroupBox(centralwidget);
        groupBoxRobotHand->setObjectName(QString::fromUtf8("groupBoxRobotHand"));
        groupBoxRobotHand->setGeometry(QRect(50, 20, 831, 271));
        frameRobotCard1 = new QFrame(groupBoxRobotHand);
        frameRobotCard1->setObjectName(QString::fromUtf8("frameRobotCard1"));
        frameRobotCard1->setGeometry(QRect(30, 50, 131, 171));
        frameRobotCard1->setFrameShape(QFrame::StyledPanel);
        frameRobotCard1->setFrameShadow(QFrame::Raised);
        pushButtonRobotCard1 = new QPushButton(frameRobotCard1);
        pushButtonRobotCard1->setObjectName(QString::fromUtf8("pushButtonRobotCard1"));
        pushButtonRobotCard1->setGeometry(QRect(0, 0, 131, 171));
        pushButtonRobotCard1->setIconSize(QSize(131, 165));
        labelRobotCard1 = new QLabel(groupBoxRobotHand);
        labelRobotCard1->setObjectName(QString::fromUtf8("labelRobotCard1"));
        labelRobotCard1->setGeometry(QRect(30, 220, 141, 31));
        labelRobotCard1->setAlignment(Qt::AlignCenter);
        labelRobotCard2 = new QLabel(groupBoxRobotHand);
        labelRobotCard2->setObjectName(QString::fromUtf8("labelRobotCard2"));
        labelRobotCard2->setGeometry(QRect(190, 220, 141, 31));
        labelRobotCard2->setAlignment(Qt::AlignCenter);
        frameRobotCard2 = new QFrame(groupBoxRobotHand);
        frameRobotCard2->setObjectName(QString::fromUtf8("frameRobotCard2"));
        frameRobotCard2->setGeometry(QRect(190, 50, 131, 171));
        frameRobotCard2->setFrameShape(QFrame::StyledPanel);
        frameRobotCard2->setFrameShadow(QFrame::Raised);
        pushButtonRobotCard2 = new QPushButton(frameRobotCard2);
        pushButtonRobotCard2->setObjectName(QString::fromUtf8("pushButtonRobotCard2"));
        pushButtonRobotCard2->setGeometry(QRect(0, 0, 131, 171));
        pushButtonRobotCard2->setIconSize(QSize(131, 165));
        labelRobotCard3 = new QLabel(groupBoxRobotHand);
        labelRobotCard3->setObjectName(QString::fromUtf8("labelRobotCard3"));
        labelRobotCard3->setGeometry(QRect(350, 220, 141, 31));
        labelRobotCard3->setAlignment(Qt::AlignCenter);
        frameRobotCard3 = new QFrame(groupBoxRobotHand);
        frameRobotCard3->setObjectName(QString::fromUtf8("frameRobotCard3"));
        frameRobotCard3->setGeometry(QRect(350, 50, 131, 171));
        frameRobotCard3->setFrameShape(QFrame::StyledPanel);
        frameRobotCard3->setFrameShadow(QFrame::Raised);
        pushButtonRobotCard3 = new QPushButton(frameRobotCard3);
        pushButtonRobotCard3->setObjectName(QString::fromUtf8("pushButtonRobotCard3"));
        pushButtonRobotCard3->setGeometry(QRect(0, 0, 131, 171));
        pushButtonRobotCard3->setIconSize(QSize(131, 165));
        labelRobotCard4 = new QLabel(groupBoxRobotHand);
        labelRobotCard4->setObjectName(QString::fromUtf8("labelRobotCard4"));
        labelRobotCard4->setGeometry(QRect(510, 220, 141, 31));
        labelRobotCard4->setAlignment(Qt::AlignCenter);
        frameRobotCard4 = new QFrame(groupBoxRobotHand);
        frameRobotCard4->setObjectName(QString::fromUtf8("frameRobotCard4"));
        frameRobotCard4->setGeometry(QRect(510, 50, 131, 171));
        frameRobotCard4->setFrameShape(QFrame::StyledPanel);
        frameRobotCard4->setFrameShadow(QFrame::Raised);
        pushButtonRobotCard4 = new QPushButton(frameRobotCard4);
        pushButtonRobotCard4->setObjectName(QString::fromUtf8("pushButtonRobotCard4"));
        pushButtonRobotCard4->setGeometry(QRect(0, 0, 131, 171));
        pushButtonRobotCard4->setIconSize(QSize(131, 165));
        labelRobotCard5 = new QLabel(groupBoxRobotHand);
        labelRobotCard5->setObjectName(QString::fromUtf8("labelRobotCard5"));
        labelRobotCard5->setGeometry(QRect(670, 220, 141, 31));
        labelRobotCard5->setAlignment(Qt::AlignCenter);
        frameRobotCard5 = new QFrame(groupBoxRobotHand);
        frameRobotCard5->setObjectName(QString::fromUtf8("frameRobotCard5"));
        frameRobotCard5->setGeometry(QRect(670, 50, 131, 171));
        frameRobotCard5->setFrameShape(QFrame::StyledPanel);
        frameRobotCard5->setFrameShadow(QFrame::Raised);
        pushButtonRobotCard5 = new QPushButton(frameRobotCard5);
        pushButtonRobotCard5->setObjectName(QString::fromUtf8("pushButtonRobotCard5"));
        pushButtonRobotCard5->setGeometry(QRect(0, 0, 131, 171));
        pushButtonRobotCard5->setIconSize(QSize(131, 165));
        labelRobotCategory = new QLabel(groupBoxRobotHand);
        labelRobotCategory->setObjectName(QString::fromUtf8("labelRobotCategory"));
        labelRobotCategory->setGeometry(QRect(230, 10, 361, 41));
        labelRobotCategory->setAlignment(Qt::AlignCenter);
        labelRoundText = new QLabel(centralwidget);
        labelRoundText->setObjectName(QString::fromUtf8("labelRoundText"));
        labelRoundText->setGeometry(QRect(230, 300, 71, 31));
        labelRoundText->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        labelUserScoreText = new QLabel(centralwidget);
        labelUserScoreText->setObjectName(QString::fromUtf8("labelUserScoreText"));
        labelUserScoreText->setGeometry(QRect(230, 330, 71, 31));
        labelUserScoreText->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        labelRobotScoreText = new QLabel(centralwidget);
        labelRobotScoreText->setObjectName(QString::fromUtf8("labelRobotScoreText"));
        labelRobotScoreText->setGeometry(QRect(230, 360, 71, 31));
        labelRobotScoreText->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        labelRound = new QLabel(centralwidget);
        labelRound->setObjectName(QString::fromUtf8("labelRound"));
        labelRound->setGeometry(QRect(320, 300, 41, 31));
        labelUserScore = new QLabel(centralwidget);
        labelUserScore->setObjectName(QString::fromUtf8("labelUserScore"));
        labelUserScore->setGeometry(QRect(320, 330, 41, 31));
        labelRobotScore = new QLabel(centralwidget);
        labelRobotScore->setObjectName(QString::fromUtf8("labelRobotScore"));
        labelRobotScore->setGeometry(QRect(320, 360, 41, 31));
        labelCardRest = new QLabel(centralwidget);
        labelCardRest->setObjectName(QString::fromUtf8("labelCardRest"));
        labelCardRest->setGeometry(QRect(690, 300, 31, 41));
        pushButtonNextRound = new QPushButton(centralwidget);
        pushButtonNextRound->setObjectName(QString::fromUtf8("pushButtonNextRound"));
        pushButtonNextRound->setEnabled(true);
        pushButtonNextRound->setGeometry(QRect(400, 350, 141, 41));
        pushButtonNextRound->setContextMenuPolicy(Qt::NoContextMenu);
        labelWinner = new QLabel(centralwidget);
        labelWinner->setObjectName(QString::fromUtf8("labelWinner"));
        labelWinner->setGeometry(QRect(370, 300, 201, 41));
        labelWinner->setAlignment(Qt::AlignCenter);
        labelCardDeck = new QLabel(centralwidget);
        labelCardDeck->setObjectName(QString::fromUtf8("labelCardDeck"));
        labelCardDeck->setGeometry(QRect(740, 300, 131, 91));
        pushButtonGameOver = new QPushButton(centralwidget);
        pushButtonGameOver->setObjectName(QString::fromUtf8("pushButtonGameOver"));
        pushButtonGameOver->setEnabled(true);
        pushButtonGameOver->setGeometry(QRect(400, 350, 141, 41));
        pushButtonGameOver->setContextMenuPolicy(Qt::NoContextMenu);
        pushButtonConfirm = new QPushButton(centralwidget);
        pushButtonConfirm->setObjectName(QString::fromUtf8("pushButtonConfirm"));
        pushButtonConfirm->setGeometry(QRect(620, 350, 101, 41));
        pushButtonConfirm->setContextMenuPolicy(Qt::NoContextMenu);
        CardGameMain->setCentralWidget(centralwidget);
        menubar = new QMenuBar(CardGameMain);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 933, 28));
        menuReset_Game = new QMenu(menubar);
        menuReset_Game->setObjectName(QString::fromUtf8("menuReset_Game"));
        CardGameMain->setMenuBar(menubar);
        statusbar = new QStatusBar(CardGameMain);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        CardGameMain->setStatusBar(statusbar);

        menubar->addAction(menuReset_Game->menuAction());
        menuReset_Game->addAction(actionReset_Game);
        menuReset_Game->addAction(actionSet_Player_s_name);
        menuReset_Game->addAction(actionAbout_me);

        retranslateUi(CardGameMain);

        QMetaObject::connectSlotsByName(CardGameMain);
    } // setupUi

    void retranslateUi(QMainWindow *CardGameMain)
    {
        CardGameMain->setWindowTitle(QCoreApplication::translate("CardGameMain", "CardGameMain", nullptr));
        actionReset_Game->setText(QCoreApplication::translate("CardGameMain", "New Game", nullptr));
        actionSet_Player_s_name->setText(QCoreApplication::translate("CardGameMain", "Set Player's Name", nullptr));
        actionAbout_me->setText(QCoreApplication::translate("CardGameMain", "About me", nullptr));
        pushButtonStartGame->setText(QCoreApplication::translate("CardGameMain", "Start", nullptr));
        groupBoxUserHand->setTitle(QCoreApplication::translate("CardGameMain", "Your Hand", nullptr));
        pushButtonUserCard1->setText(QString());
        labelUserCard1->setText(QCoreApplication::translate("CardGameMain", "labelUserCard1", nullptr));
        labelUserCard2->setText(QCoreApplication::translate("CardGameMain", "labelUserCard2", nullptr));
        pushButtonUserCard2->setText(QString());
        labelUserCard3->setText(QCoreApplication::translate("CardGameMain", "labelUserCard3", nullptr));
        pushButtonUserCard3->setText(QString());
        labelUserCard4->setText(QCoreApplication::translate("CardGameMain", "labelUserCard4", nullptr));
        pushButtonUserCard4->setText(QString());
        labelUserCard5->setText(QCoreApplication::translate("CardGameMain", "labelUserCard5", nullptr));
        pushButtonUserCard5->setText(QString());
        labelUserCategory->setText(QCoreApplication::translate("CardGameMain", "User's hand Category", nullptr));
        labelCardRestText->setText(QCoreApplication::translate("CardGameMain", "Rest:", nullptr));
        pushButtonSwap->setText(QCoreApplication::translate("CardGameMain", "Swap", nullptr));
        groupBoxRobotHand->setTitle(QCoreApplication::translate("CardGameMain", "Robot's hand", nullptr));
        pushButtonRobotCard1->setText(QString());
        labelRobotCard1->setText(QCoreApplication::translate("CardGameMain", "labelRobotCard1", nullptr));
        labelRobotCard2->setText(QCoreApplication::translate("CardGameMain", "labelRobotCard2", nullptr));
        pushButtonRobotCard2->setText(QString());
        labelRobotCard3->setText(QCoreApplication::translate("CardGameMain", "labelRobotCard3", nullptr));
        pushButtonRobotCard3->setText(QString());
        labelRobotCard4->setText(QCoreApplication::translate("CardGameMain", "labelRobotCard4", nullptr));
        pushButtonRobotCard4->setText(QString());
        labelRobotCard5->setText(QCoreApplication::translate("CardGameMain", "labelRobotCard5", nullptr));
        pushButtonRobotCard5->setText(QString());
        labelRobotCategory->setText(QCoreApplication::translate("CardGameMain", "Robot's hand Category", nullptr));
        labelRoundText->setText(QCoreApplication::translate("CardGameMain", "Round: ", nullptr));
        labelUserScoreText->setText(QCoreApplication::translate("CardGameMain", "User: ", nullptr));
        labelRobotScoreText->setText(QCoreApplication::translate("CardGameMain", "Robot: ", nullptr));
        labelRound->setText(QCoreApplication::translate("CardGameMain", "0", nullptr));
        labelUserScore->setText(QCoreApplication::translate("CardGameMain", "0", nullptr));
        labelRobotScore->setText(QCoreApplication::translate("CardGameMain", "0", nullptr));
        labelCardRest->setText(QCoreApplication::translate("CardGameMain", "52", nullptr));
        pushButtonNextRound->setText(QCoreApplication::translate("CardGameMain", "Next round", nullptr));
        labelWinner->setText(QCoreApplication::translate("CardGameMain", "Winner!", nullptr));
        labelCardDeck->setText(QCoreApplication::translate("CardGameMain", "deck", nullptr));
        pushButtonGameOver->setText(QCoreApplication::translate("CardGameMain", "Game Over", nullptr));
        pushButtonConfirm->setText(QCoreApplication::translate("CardGameMain", "Confirm", nullptr));
        menuReset_Game->setTitle(QCoreApplication::translate("CardGameMain", "Menu", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CardGameMain: public Ui_CardGameMain {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CARDGAMEMAIN_H
