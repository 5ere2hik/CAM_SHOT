#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QStandardPaths>
#include <QDir>
#include "camshooter.h"
#include "dialog.h"
#include <QDebug>
#include <QCloseEvent>
#include "qglobalshortcut.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    QObject::connect(ui->hideButton, SIGNAL(clicked()), this, SLOT(hide()));

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
    CamShooter *camshooter = new CamShooter("D:/screens");

    ui->pathLineEdit->setText(CamShooter::getPath());
    ui->startButton->setEnabled(false);
    ui->freqComboBox->setEnabled(false);
    ui->freqSpinBox->setEnabled(false);
    ui->stopButton->setEnabled(true);




    //QObject::connect(camshooter, SIGNAL(start(uint,QVariant)),camshooter, SLOT(on_start(uint,QVariant)));
    QObject::connect(ui->stopButton, SIGNAL(clicked()),camshooter, SLOT(on_stop()));
    QObject::connect(camshooter,SIGNAL(start(uint,int)),camshooter, SLOT(on_start(uint,int)));

    emit camshooter->start(ui->freqSpinBox->value(),ui->freqComboBox->currentIndex());

}


void MainWindow::on_stopButton_clicked()
{
    ui->startButton->setEnabled(true);
    ui->freqComboBox->setEnabled(true);
    ui->freqSpinBox->setEnabled(true);
    ui->stopButton->setEnabled(false);
}
