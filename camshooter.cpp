#include "camshooter.h"
#include <QDir>
#include <QStandardPaths>
#include "dialog.h"
#include <QString>
#include <QDebug>
#include <QPixmap>
#include <QScreen>
#include <QGuiApplication>
#include <QDateTime>
#include <QTimer>

QString CamShooter::path;// = QStandardPaths::locate(QStandardPaths::TempLocation, QString(), QStandardPaths::LocateDirectory) + "camshots";


CamShooter::CamShooter(QObject *parent) :
    QObject(parent)
{
    qDebug() << "Creating CamShooter object";
    if(!QDir(CamShooter::path).exists())
    {
        qDebug() << "Folder doesn't exist. Creating folder...";
        QDir().mkdir(CamShooter::path);
    }
}

CamShooter::CamShooter(const QString folderPath, QObject *parent) :
    QObject(parent)
{
    qDebug() << "Creating CamShooter object";
    CamShooter::setPath(folderPath);
    if(!QDir(CamShooter::path).exists())
    {
        qDebug() << "Folder doesn't exist. Creating folder...";
        QDir().mkdir(CamShooter::path);
    }
}

CamShooter::~CamShooter()
{
    qDebug() << "Deleting CamShooter object";
}

void CamShooter::setPath(const QString p)
{
    CamShooter::path = p;
}

void CamShooter::setDefaultPath()
{
    CamShooter::path = QStandardPaths::locate(QStandardPaths::TempLocation, QString(), QStandardPaths::LocateDirectory) + "camshots";
}

QString CamShooter::getPath()
{
    return CamShooter::path;
}


void CamShooter::makePicture()
{
    if(!QDir(CamShooter::path).exists())
    {
        qDebug() << "Folder doesn't exist. Creating folder...";
        QDir().mkdir(CamShooter::path);
    }
    QScreen *screen = QGuiApplication::primaryScreen();

    QPixmap *screenshot = new QPixmap(screen->grabWindow(0));


    screenshot->save(CamShooter::getPath() +"/"+ QDateTime::currentDateTime().toString("dd.MM.yyyy - hh.mm.ss") +".png", "png");

    delete screenshot;


}

void CamShooter::on_start(unsigned int times,int index)
{
    timer = new QTimer;

    QObject::connect(timer, SIGNAL(timeout()),this,SLOT(on_timer_overflow()));

    unsigned int msecs;

    if(index == 1)
        msecs = (3600/times)*1000;
    else if(index == 0)
        msecs = (60/times)*1000;
    else
        msecs = 60000;


    timer->start(msecs);
}

void CamShooter::on_timer_overflow()
{
    this->makePicture();
}

void CamShooter::on_stop()
{
    timer->stop();
    delete this;
}

