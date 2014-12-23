#ifndef CAMERA_H
#define CAMERA_H

#include <QWidget>
#include <QPointer>
#include "ui_selectdialog.h"


class QCamera;
class QCameraViewfinder;
class QLayout;
class QWidget;




class Camera : public QWidget
{
    Q_OBJECT

public:
    Camera(QWidget *parent = 0);
    Camera(QLayout *layout, QWidget *parent = 0);
    ~Camera();



private:
    Ui::selectDialog select_ui;
    QDialog *selectDialog;

    QCameraViewfinder *viewFinder;
    QPointer <QCamera> camera;
    static QByteArray defaultDevice;



signals:

public slots:

};

#endif  // CAMERA_H
