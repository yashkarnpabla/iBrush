#ifndef CREDITSWINDOW_H
#define CREDITSWINDOW_H

#include <QDialog>

namespace Ui {
class creditsWindow;
}

class creditsWindow : public QDialog
{
    Q_OBJECT

public:
    explicit creditsWindow(QWidget *parent = nullptr);
    ~creditsWindow();

private:
    Ui::creditsWindow *ui;
};

#endif // CREDITSWINDOW_H
