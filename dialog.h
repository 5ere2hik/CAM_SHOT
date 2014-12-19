#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
protected:
    virtual void closeEvent(QCloseEvent *event);
private slots:

    void on_yesButton_clicked();

    void on_noButton_clicked();

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
