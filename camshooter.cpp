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
    //CamShooter::setDefaultPath();
    if(!QDir(CamShooter::path).exists())
    {
        qDebug() << "Folder doesn't exist. Creating folder...";
        QDir().mkdir(CamShooter::path);
    }
}

CamShooter::CamShooter(const QString folderPath, QObject *parent) :
    QObject(parent)
{
    CamShooter::setPath(folderPath);
    if(!QDir(CamShooter::path).exists())
    {
        qDebug() << "Folder doesn't exist. Creating folder...";
        QDir().mkdir(CamShooter::path);
    }
}

CamShooter::~CamShooter()
{
    qDebug() << "deleting object";
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

void CamShooter::start(unsigned int times,QVariant per)
{
    timer = new QTimer;

    QObject::connect(timer, SIGNAL(timeout()),this,SLOT(timer_overflow()));

    unsigned int msecs;

    if(per == inHour)
        msecs = (3600/times)*1000;
    else if(per == inMinute)
        msecs = (60/times)*1000;
    else
        msecs = 60000;


    timer->start(msecs);
}

void CamShooter::timer_overflow()
{
    this->makePicture();
}
