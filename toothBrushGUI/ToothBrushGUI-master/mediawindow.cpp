/** Media Window class
 * This class is designed to allow the user to select between opening
 * the sports media interface or the news media interface
 * @author Yashkarn Pabla
 * @brief Interface to select between sports or media UI
 */

#include "mediawindow.h"
#include "ui_mediawindow.h"
#include "sportswindow.h"
#include "selectionwindow.h"
#include "newswindow.h"
#include <QPixmap>

/**
 * @brief creates media window
 * @param parent
 */
mediaWindow::mediaWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mediaWindow)
{
    ui->setupUi(this);
    QPixmap defaultPic("/home/pi/toothBrushGUI/mediaPics/mediaDefaultrsz.jpg");
    ui->mediaPicture->setPixmap(defaultPic);    //Set background picture
}

/**
 * @brief deletes media window
 */
mediaWindow::~mediaWindow()
{
    delete ui;
}

/**
 * @brief closes current window and opens sports window when clicked
 */
void mediaWindow::on_sportsButton_clicked()
{
    hide(); //Close media window
    //Open sports window
    sportsWindow sportsWindow;
    sportsWindow.setModal(true);
    sportsWindow.exec();
}

/**
 * @brief closes current window and opens previous when clicked
 */
void mediaWindow::on_mediaBackButton_clicked()
{
    hide();
    selectionWindow selectionWindowBack;
    selectionWindowBack.setModal(true);
    selectionWindowBack.exec();
}

/**
 * @brief closes current window and opens news window when clicked
 */
void mediaWindow::on_newsButton_clicked()
{
    hide(); //Close media window
    //Open news window
    newsWindow newsWindow;
    newsWindow.setModal(true);
    newsWindow.exec();
}
