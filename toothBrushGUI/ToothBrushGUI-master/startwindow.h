#ifndef STARTWINDOW_H
#define STARTWINDOW_H

#include <QMainWindow>

namespace Ui {
class startWindow;
}

class startWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit startWindow(QWidget *parent = nullptr);
    ~startWindow();

private slots:

    void on_startButton_clicked();

    void on_creditsButton_clicked();

private:
    Ui::startWindow *ui;
};

#endif // STARTWINDOW_H
