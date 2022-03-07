#ifndef NEWSWINDOW_H
#define NEWSWINDOW_H

#include <QDialog>

namespace Ui {
class newsWindow;
}

class newsWindow : public QDialog
{
    Q_OBJECT

public:
    explicit newsWindow(QWidget *parent = nullptr);
    ~newsWindow();

private slots:
    void on_newsButton_clicked();

    void on_newsBackButton_clicked();

private:
    Ui::newsWindow *ui;
};

#endif // NEWSWINDOW_H
