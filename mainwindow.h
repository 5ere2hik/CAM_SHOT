#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "camshooter.h"
#include "camera.h"

namespace Ui {
class MainWindow;
}


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    CamShooter *camshooter;

    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    virtual void closeEvent(QCloseEvent *event);
private slots:




    void on_startButton_clicked();



    void on_stopButton_clicked();

private:

    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
