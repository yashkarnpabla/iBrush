#ifndef SPORTSWINDOW_H
#define SPORTSWINDOW_H

#include <QDialog>

namespace Ui {
class sportsWindow;
}

class sportsWindow : public QDialog
{
    Q_OBJECT

public:
    explicit sportsWindow(QWidget *parent = nullptr);
    ~sportsWindow();

private slots:
    void on_sportsSelectButton_clicked();

    void on_sportsBackButton_clicked();

    void on_teamStatsButton_clicked();

    void on_upcomingGamesButton_clicked();

private:
    Ui::sportsWindow *ui;
};

#endif // SPORTSWINDOW_H
