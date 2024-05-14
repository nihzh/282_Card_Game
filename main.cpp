#include "cardgamemain.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CardGameMain w;

    // set stylesheet
    w.setStyleSheet(
        "QMainWindow#CardGameMain {"
        "   background: #bae6ba;"
        "}"
        ""
        // "QPushButton {"
        // "   background: #8cc28c;"
        // "   border-style: solid;"
        // "   border-radius: 10px;"
        // "}"
    );

    w.show();
    return a.exec();
}
