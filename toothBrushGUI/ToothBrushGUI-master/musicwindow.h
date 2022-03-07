#ifndef MUSICWINDOW_H
#define MUSICWINDOW_H

#include <QDialog>

namespace Ui {
class musicWindow;
}

class musicWindow : public QDialog
{
    Q_OBJECT

public:
    explicit musicWindow(QWidget *parent = nullptr);
    ~musicWindow();

private slots:
    void on_soundcloudSearchButton_clicked();
    
    void on_searchYoutubeButton_clicked();

    void on_musicBackButton_clicked();

private:
    Ui::musicWindow *ui;
};

#endif // MUSICWINDOW_H
