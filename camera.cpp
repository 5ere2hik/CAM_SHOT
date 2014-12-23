#include "camera.h"
#include <QObject>
#include <QCamera>
#include <QCameraViewfinder>
#include <QMessageBox>
#include <QPointer>
#include <QLayout>
#include <QCommandLinkButton>
/*
//#include "ui_camera.h"
//#include "videosettings.h"
//#include "imagesettings.h"

#include <QMediaService>
#include <QMediaRecorder>
#include <QCameraViewfinder>
#include <QMediaMetaData>

#include <QMessageBox>
#include <QPalette>



#include "mainwindow.h"
*/


QByteArray Camera::defaultDevice = QByteArray();

Camera::Camera(QWidget *parent)
{

}


Camera::Camera(QLayout *layout, QWidget *parent)
{

    QList< QByteArray > cams = QCamera::availableDevices();
        if ( !cams.contains( defaultDevice ) )
        {
            if ( cams.count() == 0 )
            {
                QMessageBox::critical( this, "Error", "Web Cams are not found!" );

                deleteLater();
                return;
            }
            else if ( cams.count() == 1 )
            {
                defaultDevice = cams.at( 0 );
            }

            else
            {
                selectDialog = new QDialog();
                selectDialog->setAttribute( Qt::WA_DeleteOnClose );
                selectDialog->setAttribute( Qt::WA_QuitOnClose, false );
                selectDialog->setWindowFlags( selectDialog->windowFlags() ^ Qt::WindowContextHelpButtonHint | Qt::MSWindowsFixedSizeDialogHint );

                select_ui.setupUi( selectDialog );

                foreach( QByteArray webCam, cams )
                {
                    QCommandLinkButton *commandLinkButton = new QCommandLinkButton( QCamera::deviceDescription( webCam ) );
                    commandLinkButton->setProperty( "webCam", webCam );

                    QObject::connect( commandLinkButton, &QCommandLinkButton::clicked, [=]( bool )
                        {
                            defaultDevice = commandLinkButton->property( "webCam" ).toByteArray();
                            selectDialog->accept();
                        }
                    );

                    select_ui.verticalLayout->addWidget( commandLinkButton );
                }

                if ( selectDialog->exec() == QDialog::Rejected )
                {
                    deleteLater();
                    return;
                }
            }


        }

        camera = new QCamera(defaultDevice);

        viewFinder = new QCameraViewfinder();
        viewFinder->setMinimumSize( 50, 50 );

        camera->setViewfinder(viewFinder);
        camera->setCaptureMode( QCamera::CaptureStillImage );

        layout->addWidget(viewFinder);


        camera->start();
}

Camera::~Camera()
{

}

/*void Camera::setCamera(const QByteArray &cameraDevice)
{
    if (cameraDevice.isEmpty())
        camera = new QCamera;
    else
        camera = new QCamera(cameraDevice);

   // connect(camera, SIGNAL(stateChanged(QCamera::State)), this, SLOT(updateCameraState(QCamera::State)));
  //  connect(camera, SIGNAL(error(QCamera::Error)), this, SLOT(displayCameraError()));

  //  mediaRecorder = new QMediaRecorder(camera);
  //  connect(mediaRecorder, SIGNAL(stateChanged(QMediaRecorder::State)), this, SLOT(updateRecorderState(QMediaRecorder::State)));

    imageCapture = new QCameraImageCapture(camera);

   // connect(mediaRecorder, SIGNAL(durationChanged(qint64)), this, SLOT(updateRecordTime()));
  //  connect(mediaRecorder, SIGNAL(error(QMediaRecorder::Error)), this, SLOT(displayRecorderError()));

 //   mediaRecorder->setMetaData(QMediaMetaData::Title, QVariant(QLatin1String("Test Title")));

 //   connect(ui->exposureCompensation, SIGNAL(valueChanged(int)), SLOT(setExposureCompensation(int)));

    camera->setViewfinder();

    updateCameraState(camera->state());
    updateLockStatus(camera->lockStatus(), QCamera::UserRequest);
    updateRecorderState(mediaRecorder->state());

    connect(imageCapture, SIGNAL(readyForCaptureChanged(bool)), this, SLOT(readyForCapture(bool)));
    connect(imageCapture, SIGNAL(imageCaptured(int,QImage)), this, SLOT(processCapturedImage(int,QImage)));
    connect(imageCapture, SIGNAL(imageSaved(int,QString)), this, SLOT(imageSaved(int,QString)));
    connect(imageCapture, SIGNAL(error(int,QCameraImageCapture::Error,QString)), this,
            SLOT(displayCaptureError(int,QCameraImageCapture::Error,QString)));

    connect(camera, SIGNAL(lockStatusChanged(QCamera::LockStatus,QCamera::LockChangeReason)),
            this, SLOT(updateLockStatus(QCamera::LockStatus,QCamera::LockChangeReason)));

    ui->captureWidget->setTabEnabled(0, (camera->isCaptureModeSupported(QCamera::CaptureStillImage)));
    ui->captureWidget->setTabEnabled(1, (camera->isCaptureModeSupported(QCamera::CaptureVideo)));

    updateCaptureMode();
    camera->start();
}*/
