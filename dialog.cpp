#include "dialog.h"
#include "ui_dialog.h"
#include <QDir>
#include <QStandardPaths>
#include <QDebug>
#include <QCloseEvent>
#include "camshooter.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);


}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::closeEvent(QCloseEvent *event)
{
    event->ignore();
}


void Dialog::on_yesButton_clicked()
{
    QDir *dir = new QDir(CamShooter::getPath());
    if(dir->exists())
    {
        if(!dir->removeRecursively())
        qDebug() << "dir hasn't been removed";
    else
        qDebug() << "dir has been removed";
    }
    else
        qDebug() << "there is no dir";

    delete dir;

    QDialog::accept();

}

void Dialog::on_noButton_clicked()
{
    qDebug() << "dir hasn't been removed";
    QDialog::accept();
}
