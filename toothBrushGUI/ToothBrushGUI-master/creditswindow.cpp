/** Credits window class
This class was designed to display the names of group members who
 contributed to this project.
 @author Mazen Baioumy
 @brief Displays form containing group members
*/

#include "creditswindow.h"
#include "ui_creditswindow.h"

/**
 * @brief creates credits window
 * @param parent
 */
creditsWindow::creditsWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::creditsWindow)
{
    ui->setupUi(this);
}

/**
 * @brief deletes credits window
 */
creditsWindow::~creditsWindow()
{
    delete ui;
}
