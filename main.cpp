#include "mainwindow.h"
#include "ImageViewer.h"
#include <QApplication>
#include <QIcon>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // Load the icon from resources
    // QIcon appIcon(":/resources/icon.svg");
    QIcon appIcon(":/resources/icon.ico");
    // Check if the icon loaded successfully
    if (appIcon.isNull()) {
        qDebug() << "Failed to load icon";
    } else {
        qDebug() << "Icon loaded successfully";
    }

    // Set the application window icon (icon shown in taskbar or window title bar)
    app.setWindowIcon(appIcon);  // For taskbar

    // Create and show the ImageViewer window
    ImageViewer viewer;
    
    // Set the window icon for ImageViewer window
    viewer.setWindowIcon(appIcon);  // For window title bar

    viewer.show();

    return app.exec();
}
