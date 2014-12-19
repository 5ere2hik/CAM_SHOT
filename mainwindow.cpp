#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QStandardPaths>
#include <QDir>
#include "camshooter.h"
#include "dialog.h"
#include <QDebug>
#include <QCloseEvent>



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->freqComboBox->setItemData(0,inMinute);
    ui->freqComboBox->setItemData(1,inHour);

    CamShooter *camshooter = new CamShooter("D:/screens");
    ui->pathLineEdit->setText(CamShooter::getPath());






}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    Dialog *exitDialog = new Dialog;
    exitDialog->setWindowTitle("Внимание!");
    exitDialog->exec();
}



void MainWindow::on_startButton_clicked()
{
    camshooter = new CamShooter("D:/screens");




    if(ui->startButton->)
    {
        ui->startButton->setText("Cтоп");
        ui->freqComboBox->setEnabled(false);
        ui->freqSpinBox->setEnabled(false);


        camshooter = new CamShooter(CamShooter::getPath());
        camshooter->start(ui->freqSpinBox->value(),ui->freqComboBox->currentData() );
    }
    else
    {
        ui->startButton->setText("Cтарт");
        ui->freqComboBox->setEnabled(false);
        ui->freqSpinBox->setEnabled(false);


      //  camshooter->stop();
        delete camshooter;
    }
}




