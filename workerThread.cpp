#include "workerThread.h"

WorkerThread::WorkerThread(QObject *parent) 
    : QThread(parent), inputImage()  // Initialize inputImage
{
    // No need to initialize 'image' if it's not defined
}

void WorkerThread::processImage(const QImage &image)
{
    inputImage = image;  // Store the input image
    start();  // Start the thread, which will call the run() method
}

void WorkerThread::run()
{
    // Process the image (for example, converting to grayscale)
    QImage processedImage = inputImage;  
    for (int y = 0; y < processedImage.height(); ++y) {
        for (int x = 0; x < processedImage.width(); ++x) {
            QColor color = processedImage.pixelColor(x, y);
            int gray = qGray(color.rgb());
            processedImage.setPixelColor(x, y, QColor(gray, gray, gray));
        }
    }

    // Emit the signal once the work is done
    emit workDone(processedImage);
}
