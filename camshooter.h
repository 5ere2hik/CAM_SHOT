#ifndef CAMSHOOTER_H
#define CAMSHOOTER_H

#include <QObject>
class QString;
class QTimer;
class QCamera;

//enum period {inMinute, inHour};
//Q_DECLARE_METATYPE(period)


class CamShooter : public QObject
{

    Q_OBJECT
private:

    static QString path;
    QTimer *timer;

public:
    explicit CamShooter(QObject *parent = 0);
    explicit CamShooter(const QString folderPath, QObject *parent = 0);
    ~CamShooter();



    void makePicture();
    static void setPath(const QString p);
    static void setDefaultPath();
    static QString getPath();




signals:

    void start(unsigned int times, int index );



public slots:
    void on_timer_overflow();
    void on_start(unsigned int times, int index);
    void on_stop();

};



#endif // CAMSHOOTER_H
