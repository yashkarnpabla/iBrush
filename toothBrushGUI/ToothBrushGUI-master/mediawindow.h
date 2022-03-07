#ifndef MEDIAWINDOW_H
#define MEDIAWINDOW_H

#include <QDialog>

namespace Ui {
class mediaWindow;
}

class mediaWindow : public QDialog
{
    Q_OBJECT

public:
    explicit mediaWindow(QWidget *parent = nullptr);
    ~mediaWindow();

private slots:
    void on_sportsButton_clicked();

    void on_mediaBackButton_clicked();

    void on_newsButton_clicked();

private:
    Ui::mediaWindow *ui;
};

#endif // MEDIAWINDOW_H
