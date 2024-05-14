#ifndef CARDGAMEMAIN_H
#define CARDGAMEMAIN_H

#include <QMainWindow>
#include "gamecontroller.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class CardGameMain;
}
QT_END_NAMESPACE

class CardGameMain : public QMainWindow
{
    Q_OBJECT

public:
    CardGameMain(QWidget *parent = nullptr);
    ~CardGameMain();
    void initializeGame();

private slots:
    void reInitialize();
    void setPlayer();
    void aboutMe();

private:
    Ui::CardGameMain *ui;
    GameController* controller;
    QString username;
};
#endif // CARDGAMEMAIN_H
