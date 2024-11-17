#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ImageViewer.h"
#include <QDebug>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), imageviewer(new ImageViewer(this))
{
    ui->setupUi(this);

    // Connect each button to the respective slot in ImageViewer or MainWindow
    bool success = connect(ui->pushButton1, &QPushButton::clicked, imageviewer, &ImageViewer::onZoomInButtonClicked);
qDebug() << "Connection successful for Button 1 (Zoom In):" << success;

    success = connect(ui->pushButton2, &QPushButton::clicked, imageviewer, &ImageViewer::onZoomOutButtonClicked);
    qDebug() << "Connection successful for Button 2 (Zoom Out):" << success;

    success = connect(ui->pushButton3, &QPushButton::clicked, imageviewer, &ImageViewer::onFileButtonClicked);
    qDebug() << "Connection successful for Button 3 (Open File):" << success;

    success = connect(ui->pushButton4, &QPushButton::clicked, imageviewer, &ImageViewer::onSaveButtonClicked);
    qDebug() << "Connection successful for Button 4 (Save File):" << success;
}

MainWindow::~MainWindow()
{
   delete ui;
   delete imageviewer;
}

void MainWindow::onPushButtonClicked()
{
   qDebug() << "Button clicked!";
       
    QString filePath = QFileDialog::getOpenFileName(this, "Open Image", "", "Images (*.png *.xpm *.jpg *.jpeg *.bmp *.gif *.tiff *.webp *.svg)");

//    imageviewer->displayImage(filePath);
   qDebug() << "display is running";
   imageviewer->resize(900,600);
   imageviewer-> setMinimumSize(900,600);
   imageviewer->show();
   imageviewer->raise();

}

