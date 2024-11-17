#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QApplication>
#include <QWidget>
#include <QFileDialog>
#include <QPushButton>
#include <qcursor.h>
#include <QLabel>
#include <QPixmap>
#include <QVBoxLayout>
#include <qmainwindow.h>
#include <QTime>
#include <QTimer>
#include <QColor>
#include <QPainter>
#include <QString>
#include "ImageViewer.h"
#include "ui_mainwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui
{
    class MainWindow;
}
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr); // Constructor
    ~MainWindow();                                  // Destructor

private slots:
    void onPushButtonClicked();
    
private:
    Ui::MainWindow *ui; // pointer to the QI compomnents
    ImageViewer *imageviewer;
};

#endif