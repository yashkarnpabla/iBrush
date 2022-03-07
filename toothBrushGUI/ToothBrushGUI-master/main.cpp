/** Main class
 * This class is designed to launch the start window which acts as the
 * opening interace of our program.
 * @author Obaida Kamil
 * @brief launches start window
 */

#include "startwindow.h"
#include <QApplication>

/**
 * @brief main
 * @param argc
 * @param argv
 * @return exit status
 */
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    startWindow w;
    w.show();

    return a.exec();
}
