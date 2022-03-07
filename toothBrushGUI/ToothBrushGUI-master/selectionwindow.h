#ifndef SELECTIONWINDOW_H
#define SELECTIONWINDOW_H

#include <QDialog>

namespace Ui {
class selectionWindow;
}

class selectionWindow : public QDialog
{
    Q_OBJECT

public:
    explicit selectionWindow(QWidget *parent = nullptr);
    ~selectionWindow();

private slots:

    void on_musicButton_clicked();

    void on_mediaButton_clicked();

    void on_weatherButton_clicked();

    void updateTime();

private:
    Ui::selectionWindow *ui;
    QTimer *timer_1m;
};

#endif // SELECTIONWINDOW_H
