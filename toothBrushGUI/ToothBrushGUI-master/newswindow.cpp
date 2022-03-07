/** News window class
This class is designed to allow the user to open and view the news
 from a variety of different outlets.
 @author Mazen Baioumy
 @brief displays news to user
*/

#include "newswindow.h"
#include "ui_newswindow.h"
#include "mediawindow.h"
#include <QDesktopServices>
#include <QUrl>
#include <QPixmap>

/**
 * @brief creates news window
 * @param parent
 */
newsWindow::newsWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::newsWindow)
{
    ui->setupUi(this);

    QPixmap defaultNewsPic("/home/pi/toothBrushGUI/newsPics/newsBackgroundrsz.jpg");

    ui->newsPicture->setPixmap(defaultNewsPic); //Set default background image

    //To make check box's more visible
    ui->label1->setStyleSheet("QLabel { background-color : grey;}");
    ui->label2->setStyleSheet("QLabel { background-color : grey;}");
}

/**
 * @brief deletes news window
 */
newsWindow::~newsWindow()
{
    delete ui;
}

/**
 * @brief opens media source based on user input after button click
 */
void newsWindow::on_newsButton_clicked()
{
    //CTV
    if (ui->newsComboBox->currentText() == "CTV") {

        QPixmap CTVpic("/home/pi/toothBrushGUI/newsPics/CTVrsz.png");
        ui->newsSourcePic->setPixmap(CTVpic);

        //YOUTUBE
        if (ui->youtubeCheckBox->isChecked()) {
            QDesktopServices::openUrl(QUrl("https://www.youtube.com/c/CTVNews/videos"));
        }

        //WEBSITE
        if (ui->websiteCheckBox->isChecked()) {
            QDesktopServices::openUrl(QUrl("https://www.ctvnews.ca/"));
        }
    }

    //CBC
    if (ui->newsComboBox->currentText() == "CBC") {

        QPixmap CBCpic("/home/pi/toothBrushGUI/newsPics/CBCrsz.png");
        ui->newsSourcePic->setPixmap(CBCpic);

        if (ui->youtubeCheckBox->isChecked()) {
            QDesktopServices::openUrl(QUrl("https://www.youtube.com/c/CBCNews/videos"));
        }

        if (ui->websiteCheckBox->isChecked()) {
            QDesktopServices::openUrl(QUrl("https://www.cbc.ca/news"));
        }
    }

    //FOX
    if (ui->newsComboBox->currentText() == "FOX") {

        QPixmap FOXpic("/home/pi/toothBrushGUI/newsPics/FOXrsz.png");
        ui->newsSourcePic->setPixmap(FOXpic);

        if (ui->youtubeCheckBox->isChecked()) {
            QDesktopServices::openUrl(QUrl("https://www.youtube.com/c/FoxNews/videos"));
        }

        if (ui->websiteCheckBox->isChecked()) {
            QDesktopServices::openUrl(QUrl("https://www.foxnews.com/"));
        }
    }

    //CNN
    if (ui->newsComboBox->currentText() == "CNN") {

        QPixmap CNNpic("/home/pi/toothBrushGUI/newsPics/CNNrsz.png");
        ui->newsSourcePic->setPixmap(CNNpic);

        if (ui->youtubeCheckBox->isChecked()) {
            QDesktopServices::openUrl(QUrl("https://www.youtube.com/user/CNN/videos"));
        }

        if (ui->websiteCheckBox->isChecked()) {
            QDesktopServices::openUrl(QUrl("https://www.cnn.com/"));
        }
    }

}

/**
 * @brief closes current window and opens previous window on button click
 */
void newsWindow::on_newsBackButton_clicked()
{
    hide();
    mediaWindow mediaWindowBack;
    mediaWindowBack.setModal(true);
    mediaWindowBack.exec();
}
