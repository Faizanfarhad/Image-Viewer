#include "ImageViewer.h"
#include "ui_mainwindow.h"
#include "workerThread.h"
#include <QDebug>

ImageViewer::ImageViewer(QWidget *parent)
   : QWidget(parent),
      item(nullptr),                  // 1st
      cropRect(new QGraphicsRectItem()),  // 2nd
      pixmapItem(new QGraphicsPixmapItem()), // 3rd
      scene(new QGraphicsScene(this)), // 4th
      view(new QGraphicsView(scene, this)), // 5th
      imageLabel(new QLabel(this)), // 6th
      currentImage(),                // 7th
      originalImage(),               // 8th
      CurrentScale(1.0),             // 9th
      imageLoaded(false),            // 10th
      isDrawing(false),              // 11th
      lastPoint(),                   // 12th
      currentShape(nullptr)             
      {

    worker = new WorkerThread(this);  // Initialize the worker thread
    connect(worker, &WorkerThread::workDone, this, &ImageViewer::onWorkDone);
   
    // Create the main layout
    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    // Create the button layout and add the buttons
    QHBoxLayout *buttonLayout = new QHBoxLayout;

    /* Button Created */
    QPushButton *ZoomInButton = new QPushButton("Zoom In", this);
    QPushButton *ZoomOutButton = new QPushButton("Zoom Out", this);
    QPushButton *FileButton = new QPushButton("Open File", this);
    QPushButton *SaveButton = new QPushButton("Save Image", this);
    QPushButton *drawButton = new QPushButton("Edit", this);
    QPushButton *rotateButton = new QPushButton("Rotate Image", this);
    QPushButton *deleteButton = new QPushButton("Delete Image", this);
    // QPushButton *cropButton = new QPushButton("Crop Image", this);
    

    /* Button creations Ends Here */

    /* Button Designing Start here */

    ZoomInButton->setStyleSheet("background-color: rgb(173, 216, 230);");
    ZoomOutButton->setStyleSheet("background-color: rgb(144, 238, 144);");
    FileButton->setStyleSheet("background-color: rgb(240, 128, 128);");
    SaveButton->setStyleSheet("background-color : rgb(250, 250, 210);");
    drawButton->setStyleSheet("background-color: rgb(255, 218, 185);");
    rotateButton->setStyleSheet("background-color: rgb(230, 230, 250);");
    deleteButton->setStyleSheet("background-color: rgb(245, 255, 250);");
    // cropButton->setStyleSheet("background-color :rgb(255,255,173);");

    /* Button Design Ends Here */

    /* Button getting add in window */

    buttonLayout->addWidget(ZoomInButton);
    buttonLayout->addWidget(ZoomOutButton);
    buttonLayout->addWidget(FileButton);
    buttonLayout->addWidget(SaveButton);
    buttonLayout->addWidget(drawButton);
    buttonLayout->addWidget(rotateButton);
    buttonLayout->addWidget(deleteButton);
    // buttonLayout->addWidget(cropButton);

    /* Button getting add in window  Ends here */

    /*  crop function strat here  */
    // scene->setSceneRect(QRectF(0,0,890,630));
    
    
    cropRect->setPen(QPen(Qt::DashLine));
    cropRect->setBrush(QBrush(Qt::transparent));
    scene->addItem(pixmapItem);
    scene->addItem(cropRect);
    cropRect->setVisible(false); 

    /* Crop Functions Ends Here*/

    /* Window Functions  Start Here */

    view->setRenderHint(QPainter::Antialiasing);
    view->setRenderHint(QPainter::SmoothPixmapTransform);
    view->setStyleSheet("border: 1px solid red;");
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    mainLayout->addLayout(buttonLayout);
    mainLayout->setAlignment(buttonLayout, Qt::AlignTop | Qt::AlignLeft);
    mainLayout->addWidget(view);
    setLayout(mainLayout);

    setWindowTitle("Image Viewer");
    resize(890, 630);

    /* Window Functions Ends Here  */

    /* Connection  of Buttons Start here */

    connect(ZoomInButton, &QPushButton::clicked, this, &ImageViewer::onZoomInButtonClicked);
    connect(ZoomOutButton, &QPushButton::clicked, this, &ImageViewer::onZoomOutButtonClicked);
    connect(FileButton, &QPushButton::clicked, this, &ImageViewer::onFileButtonClicked);
    connect(SaveButton, &QPushButton::clicked, this, &ImageViewer::onSaveButtonClicked);
    connect(drawButton, &QPushButton::clicked, this, &ImageViewer::startDrawing);
    connect(rotateButton, &QPushButton::clicked, this, &ImageViewer::rotateImage);
    connect(deleteButton, &QPushButton::clicked, this, &ImageViewer::deleteCurrentImage);
    // connect(cropButton, &QPushButton::clicked, this, &ImageViewer::on_cropButton_clicked);

    /*Connection of Buttons is Ends Here */
    /* Constructor Code Ends Here */
}

ImageViewer::~ImageViewer()
{
    delete worker;
    delete scene;
    delete view; 
}
void ImageViewer::loadImage(const QImage &image)
{
     if (pixmapItem != nullptr)
    {
        scene->removeItem(pixmapItem);
        delete pixmapItem;
        pixmapItem = nullptr;
    }
    currentImage = image;
     originalImage = QPixmap::fromImage(image);
    pixmapItem = new QGraphicsPixmapItem(originalImage);
     scene->addItem(pixmapItem);
    imageLoaded = true;
    CurrentScale = 1.0; // Reset scaling
    view->fitInView(pixmapItem, Qt::KeepAspectRatio);

    // Update the scene and log success
    scene->update();
    qDebug() << "Image loaded successfully.";
}
void ImageViewer::processImageInBackground(){
  
       if (!imageLoaded) {
        return; 
    }
    WorkerThread* worker = new WorkerThread(this);  
    connect(worker, &WorkerThread::workDone, this, &ImageViewer::onWorkDone);
    worker->processImage(currentImage);  
    worker->start();
}      
void ImageViewer::onWorkDone(const QImage &processedImage)
{
    if (processedImage.isNull()) {
        QMessageBox::warning(this, "Error", "Processed image is invalid.");
        return;
    }
    currentImage = processedImage;  // Update the current image
    updateImageDisplay();

    delete worker;
}
void ImageViewer::openImage()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open Image", "", "Images (*.png *.jpg *.bmp)");
    if (!fileName.isEmpty())
    {
        if (!currentImage.load(fileName))
        {
            QMessageBox::warning(this, "Load Image", "Failed to load image.");
            return;
        }
        imageLoaded = true;
        CurrentScale = 1.0;   // Reset scale
                 view->fitInView(pixmapItem, Qt::KeepAspectRatio);
        updateImageDisplay(); // Trigger a repaint
    }
}
void ImageViewer::resizeEvent(QResizeEvent *event)
{
    QWidget::resizeEvent(event);

    if (!currentImage.isNull())
    {
        view->fitInView(scene->itemsBoundingRect(), Qt::KeepAspectRatio);
        view->resetTransform();
        view->scale(CurrentScale, CurrentScale);
        // updateImageDisplay(); // Trigger a repaint
    }
}
void ImageViewer::onZoomInButtonClicked()
{
    if (!imageLoaded)
    {
        return;
    }
    
    double zoomfactor = 1.2; // Zoom out by 20%
    CurrentScale *= zoomfactor;
    view->scale(zoomfactor , zoomfactor);
}
void ImageViewer::onZoomOutButtonClicked()
{
    if (!imageLoaded)
    {
        return;
    }
    double zoomfactor = 0.8;
    CurrentScale *= zoomfactor;
    view->scale(zoomfactor, zoomfactor);
}
void ImageViewer::rotateImage()
{

    if (imageLoaded)
    {
        QTransform transform;
        transform.rotate(90);
        currentImage = currentImage.transformed(transform);
        originalImage = QPixmap::fromImage(currentImage);
        view->resetTransform();                  // Reset transformation before applying a new one
        view->scale(CurrentScale, CurrentScale); // Apply the new scale
        updateImageDisplay();
    }
}
void ImageViewer::deleteCurrentImage()
{
    if (!imageLoaded)
    {
        QMessageBox::warning(this, "No Image", "There is no image to delete!");
        return;
    }

    scene->clear(); // Remove all items from the scene
    imageLoaded = false;
    currentImage = QImage();
    originalImage = QPixmap();
    view->resetTransform();
    update();
}
void ImageViewer::onFileButtonClicked()
{
    QString filePath = QFileDialog::getOpenFileName(
        this,
        "Open Image",
        "",
        "Images (*.png *.xpm *.jpg *.jpeg *.bmp *.gif *.tiff *.webp *.svg)");

    if (!filePath.isEmpty())
    {
        QImage image(filePath);
        loadImage(image);
    }
}
void ImageViewer::updateImageDisplay()
{
    if (!currentImage.isNull())
    {
        pixmapItem->setPixmap(QPixmap::fromImage(currentImage));
        scene->update();
        view->fitInView(scene->itemsBoundingRect(), Qt::KeepAspectRatio);
    }
}
void ImageViewer::onSaveButtonClicked()
{
    if (!imageLoaded)
    {
        QMessageBox::warning(this, "Save Image", "Failed To Save Image!");
        return;
    }else{
        qDebug() << "Image Save SuccessFully";
    }
    QString filePath = QFileDialog::getSaveFileName(
        this,
        "Save Image",
        "",
        "Images (*.png *.xpm *.jpg *.jpeg *.bmp *.gif *.tiff *.webp *.svg)");

    if (!filePath.isEmpty())
    {
        // Use originalImage instead of getting it from label
        if (!originalImage.isNull())
        {
             if (!currentImage.save(filePath))
        {
            QMessageBox::warning(this, "Save Image", "Failed to save the image.");
        }
            else
            {
                qDebug() << "Image saved successfully to" << filePath;
            }
        }
        else
        {
            qDebug() << "Error: No image to save.";
        }
    }
}
void ImageViewer::saveImageInternal()
{
    // Implement the logic for saving the image
    QString fileName = QFileDialog::getSaveFileName(this, "Save Image", "", "Images (*.png *.xpm *.jpg *.jpeg *.bmp *.gif *.tiff *.webp *.svg)");
    if (!fileName.isEmpty())
    {
        if (!currentImage.save(fileName))
        {
            QMessageBox::warning(this, "Save Image", "Failed to save image.");
        }
    }
}
/* crop Function*/

// void ImageViewer::on_loadButton_clicked()
// {  
//      QString fileName = QFileDialog::getOpenFileName(this, tr("Open Image"), "", tr("Image Files (*.png *.xpm *.jpg *.jpeg *.bmp *.gif *.tiff *.webp *.svg)"));
//     if (!fileName.isEmpty())
//     {
//         currentImage.load(fileName);
//         if (!currentImage.isNull())
//         {
//         pixmapItem->setPixmap(QPixmap::fromImage(currentImage));
//         cropRect->setVisible(true);
//         cropRect->setRect(pixmapItem->boundingRect().adjusted(10, 10, -10, -10));
//         imageLoaded = true;           
//         }else{
//             qDebug() <<"Failed To Load Image";
//         }        
//     }
// }

// void ImageViewer::on_cropButton_clicked()
// {
//     if (cropRect->isVisible() && !currentImage.isNull())
//     {
//         QRectF rect = cropRect->rect();
//         rect = rect.intersected(QRect(0,0,currentImage.width(),currentImage.height()));
// if (rect.width() <= 0 || rect.height() <= 0){
//     qDebug() << "Invalid Crop Area : Width or Hiegth is Zero";
//     return;
// }
//         QImage croppedImage = currentImage.copy(rect.toRect());       
//         if (croppedImage.isNull())
//         {
//             qDebug() << " Failed To Crop the Image";
//             return;
//         }       
//         if (pixmapItem->scene() != scene)
//         {
//             qDebug() <<"Pixmap item is not part of the scene";
//         }      
//         pixmapItem->setPixmap(QPixmap::fromImage(croppedImage));
//         currentImage = croppedImage;
//         cropRect->setVisible(false);
//         qDebug()<< "Image Cropped SuccessFully";
//     }else{
//         qDebug()<< "Crop failed, either image is not loaded or crop rectangle is not available";
//     }
// }

// void ImageViewer::on_saveButton_clicked()
// {
//     if (!currentImage.isNull())
//     {
//         QString saveFileName = QFileDialog::getSaveFileName(this, tr("Save Image"), tr("Image Files (*.png *.xpm *.jpg *.jpeg *.bmp *.gif *.tiff *.webp *.svg)"));
//         if (!saveFileName.isEmpty())
//         {
//             currentImage.save(saveFileName);
//         }
//     }else{
//         qDebug() << " No image to save";
//     }    
// }   

/* Crop Functions Ends Here */

void ImageViewer::startDrawing()
{
    isDrawing = true;
}
// void ImageViewer::displayImage(const QString &fileName)
// {
//     if (currentImage.load(fileName))
//     {
//         qDebug() << "Image loaded successfully!";
//         originalImage = QPixmap::fromImage(currentImage);
//         imageLoaded = true;
//         if (pixmapItem != nullptr)
//         {
//             scene->removeItem(pixmapItem); // Remove existing item if any
//             delete pixmapItem;
//         }     
//         pixmapItem = new QGraphicsPixmapItem(originalImage);
//         scene->addItem(pixmapItem);
//         view->fitInView(pixmapItem, Qt::KeepAspectRatio);
//         view->update();
//     }
//     else
//     {
//         QMessageBox::warning(this, "Image Viewer", "Failed to load image.");
//     }
// }
void ImageViewer::drawShape(QGraphicsItem *shape)
{
    if (shape)
    {
        currentShape = shape;
        scene->addItem(shape);
    }
}
void ImageViewer::addTextToImage(const QString &text)
{
    if (imageLoaded)
    {
        QPainter painter(&currentImage);
        painter.setPen(QPen(Qt::black));
        painter.setFont(QFont("Arial", 30));
        painter.drawText(10, 50, text);
        originalImage = QPixmap::fromImage(currentImage);
        QGraphicsPixmapItem *imageItem = new QGraphicsPixmapItem(originalImage);
        scene->clear(); // Clear the scene before adding the new image
        scene->addItem(imageItem);
    }
}
void ImageViewer::scaleImage(double factor)
{
    if (!imageLoaded)
        return;

    CurrentScale *= factor;
    view->scale(factor, factor);
}
// Mouse Press Event
void ImageViewer::mousePressEvent(QMouseEvent *event)
{
    if (isDrawing)
    {
        lastPoint = event->pos();
        isDrawing = true;
        qDebug() << "Mouse pressed at" << lastPoint;
    }
}
void ImageViewer::mouseMoveEvent(QMouseEvent *event)
{
    if (isDrawing && event->buttons() & Qt::LeftButton)
    {
        QPainter painter(&currentImage);
        painter.setPen(QPen(Qt::black, 3));
        painter.drawLine(lastPoint, event->pos());
        lastPoint = event->pos();
        originalImage = QPixmap::fromImage(currentImage);

        scene->clear();
        QGraphicsPixmapItem *imageItem = new QGraphicsPixmapItem(originalImage);
        scene->addItem(imageItem); // Clear the scene before adding the new image
        view->fitInView(imageItem, Qt::KeepAspectRatio);
        qDebug() << "Drawing at " << lastPoint;
    }
}
// ImageViewer.cp
void ImageViewer::onPressMouseLeftButton()
{
    // Example of handling left mouse button press
    QPoint mousePos = QCursor::pos(); // Get the mouse position
    qDebug() << "Mouse left button pressed at:" << mousePos;
}
void ImageViewer::mouseReleaseEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    if (isDrawing)
    {
        isDrawing = false;
    }
}
void ImageViewer::paintEvent(QPaintEvent * /* event */)
{
    QPainter painter(this);
    if (!currentImage.isNull())
    {
        QSize widgetSize = this->size();
        QImage scaledImage = currentImage.scaled(widgetSize, Qt::KeepAspectRatio, Qt::SmoothTransformation);
        int x = (widgetSize.width() - scaledImage.width()) / 2;
        int y = (widgetSize.height() - scaledImage.height()) / 2;
        painter.drawImage(x, y, scaledImage);
    }
   
}
