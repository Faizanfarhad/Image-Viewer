#ifndef IMAGEVIEWER_H
#define IMAGEVIEWER_H
#include "workerThread.h"
#include <QGraphicsItem>
#include <QString>
#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QPixmap>
#include <QImage>         // For QImage
#include <QPainter>       // For QPainter to draw on the image
#include <QMouseEvent>    // For mouse event handling (mousePressEvent, mouseMoveEvent)
#include <QFileDialog>    // For file dialogs (e.g., for saving the image)
#include <QPen>           // For setting the pen in QPainter
#include <QBrush>         // For setting brush (optional, if you're using fills)
#include <QTransform>     // For rotating the image using QTransform
#include <QGraphicsScene> // For using QGraphicsScene for advanced editing
#include <QGraphicsView>
#include <QMessageBox>
#include <QThread>
#include <QPointF>
#include <QObject>

class ImageViewer : public QWidget
{
    Q_OBJECT

public:
    explicit ImageViewer(QWidget *parent = nullptr);
    ~ImageViewer();
    void loadImage(const QImage &image);
    void processImageInBackground();

signals:
    void updateItemGeometry(QPointF newPos);

public slots:
    void onWorkDone(const QImage  &processedImage);
    void onZoomInButtonClicked();
    // void displayImage(const QString &filepath);
    void onPressMouseLeftButton();
    void onZoomOutButtonClicked();
    void onFileButtonClicked();
    void onSaveButtonClicked();
    void updateImageDisplay();
    void saveImageInternal();
    void startDrawing();
    void deleteCurrentImage();
    void rotateImage();
    void addTextToImage(const QString &text);
    void scaleImage(double factor);
    // void onupdateItemGeometry(QPointF newPos);

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void paintEvent(QPaintEvent *event) override;

private slots:
    // void on_loadButton_clicked();
    // void on_cropButton_clicked();
    // void on_saveButton_clicked();
    

private:
    WorkerThread *worker;
    void openImage();
    void resizeEvent(QResizeEvent *event);
    void drawShape(QGraphicsItem *shape);
    void initializeGraphicsView();

    QGraphicsItem *item;             // 1st
    QGraphicsRectItem *cropRect;     // 2nd
    QGraphicsPixmapItem *pixmapItem; // 3rd
    QGraphicsScene *scene;           // 4th
    QGraphicsView *view;             // 5th
    QLabel *imageLabel;              // 6th
    QImage currentImage;             // 7th
    QPixmap originalImage;           // 8th
    double CurrentScale;             // 9th
    bool imageLoaded;                // 10th
    bool isDrawing;                  // 11th
    QPoint lastPoint;                // 12th
    QGraphicsItem *currentShape;     // 13th (last)
    // QThread *thread;
    // Ui::ImageViewer *ui;
};

#endif // IMAGEVIEWER_H
