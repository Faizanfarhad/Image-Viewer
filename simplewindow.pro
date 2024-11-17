QT += core gui svg  # Add svg if you are using SVG icons

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ImageViewer
TEMPLATE = app

SOURCES += \
    main.cpp \
    ImageViewer.cpp \
    workerThread.cpp \
    mainwindow.cpp

HEADERS += \
    mainwindow.h \
    workerThread.h \
    ImageViewer.h

FORMS += \
    mainwindow.ui

RESOURCES += resources.qrc  # Ensure this line is present
