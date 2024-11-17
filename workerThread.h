#ifndef WORKERTHREAD_H
#define WORKERTHREAD_H

#include <QThread>
#include <QImage>
#include <QColor>

class WorkerThread : public QThread
{
    Q_OBJECT  // This macro is necessary for Qt's signal-slot mechanism

public:
    explicit WorkerThread(QObject *parent = nullptr);
    void processImage(const QImage &image);  // Method to pass the image to the worker thread
    void run() override;  // The method that gets executed in the background thread

signals:
    void workDone(const QImage &processedImage);  // Signal to notify when the work is done

private:
    QImage inputImage;  // Member variable to hold the image to be processed
};

#endif // WORKERTHREAD_H
