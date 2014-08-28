#ifndef DESIGNERVIEW_H
#define DESIGNERVIEW_H

#include "WinDllMacros.h"
#include<QGraphicsView>

class QGraphicsView;
class QGraphicsScene;
class QDragEnterEvent;
class QWheelEvent;
class QKeyEvent;

//! The DesignerView class provides widget for displaying the contents of DesignerScene
//!
//! Belongs to SampleDesigner
//! Currently contains logic for zooming, deleting objects
class BA_CORE_API_ DesignerView : public QGraphicsView
{
    Q_OBJECT

public:

    explicit DesignerView(QGraphicsScene *scene, QWidget *parent = 0);
    virtual ~DesignerView(){}

    enum SelectionModes { SimpleSelectionMode, RubberSelectionMode, HandDragMode};
    int getSelectionMode() const;

signals:
    void selectionModeChanged(int);

public slots:
    void onSelectionMode(int);
    void onCenterView();
    void onChangeScale(double);
    void deleteSelectedItems();

    void zoomIn();
    void zoomOut();


protected:
//    void wheelEvent(QWheelEvent *event);
//    void scaleView(qreal scaleFactor);
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);


};

#endif // DESIGNERVIEW_H
