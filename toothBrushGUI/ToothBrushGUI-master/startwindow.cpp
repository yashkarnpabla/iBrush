/** Start window class
This class is designed to provide the opening interface where the
 * user can view the project credits or start the toothbrush and move
 * into the selection window interface.
 * @author Nick Hamel
 * @brief starting UI for project
 */


#include "startwindow.h"
#include "ui_startwindow.h"
#include "selectionwindow.h"
#include "creditswindow.h"
#include <QPixmap>

/**
 * @brief creates start window
 * @param parent
 */
startWindow::startWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::startWindow)
{
    ui->setupUi(this);

    QPixmap startWindowBackground("/home/pi/toothBrushGUI/startWindowPics/startWindowBackground.jpg");

    ui->startWindowPicture->setPixmap(startWindowBackground);
}

/**
 * @brief deletes start window
 */
startWindow::~startWindow()
{
    delete ui;
}


/**
 * @brief closes current window and opens selection window on button click
 */
void startWindow::on_startButton_clicked()
{
    hide();
    selectionWindow selectionWindow;
    selectionWindow.setModal(true);
    selectionWindow.exec();
}

/**
 * @brief opens credit window on button click
 */
void startWindow::on_creditsButton_clicked()
{
    creditsWindow creditsWindow;
    creditsWindow.setModal(true);
    creditsWindow.exec();
}
