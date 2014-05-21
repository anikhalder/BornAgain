#include "SampleViewComponents.h"
#include "widgetbox.h"
#include "SampleDesigner.h"


//SampleTreeInspector::SampleTreeInspector(QWidget *parent)
//    : QWidget(parent)
//{
//    setMinimumSize(128, 128);
//    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

//}



//SampleWidgetBoxInterface *SampleViewComponents::createWidgetBox(SampleDesignerInterface *core, QWidget *parent)
//{
//    QDesignerWidgetBoxInterface *result = new qdesigner_internal::WidgetBox(core, parent);
//    result->setFileName(QStringLiteral(":/widgetbox/widgetbox.xml"));
//    result->load();
//    result->setWindowTitle(QLatin1String("Widget Box"));
//    result->setObjectName(QLatin1String("WidgetBox"));
//    //m_sampleEditor->setWidgetBox(wb);
//    return result;
//}

SampleWidgetBox *SampleViewComponents::createWidgetBox(
        SampleDesignerInterface *core, QWidget *parent)
{
    return new SampleWidgetBox(core, parent);
}

//SamplePropertyEditorInterface *SampleViewComponents::createPropertyEditor(QWidget *parent)
SamplePropertyEditor *SampleViewComponents::createPropertyEditor(
        QItemSelectionModel *selection_model, QWidget *parent)
{
    //SamplePropertyEditorInterface *result = new SamplePropertyEditorInterface(parent);
//    SamplePropertyEditor *result = new SamplePropertyEditor(core, parent);
//    result->setWindowTitle(QLatin1String("Property Editor"));
//    result->setObjectName(QLatin1String("PropertyEditor"));
    return new SamplePropertyEditor(selection_model, parent);
}

ItemTreeView *SampleViewComponents::createTreeView(
        SessionModel *sample_model, QWidget *parent)
{
    ItemTreeView *tree_view = new ItemTreeView(parent);
    tree_view->setModel(sample_model);
    tree_view->setAllColumnsShowFocus(true);
    tree_view->setWindowTitle(QString("Object Tree View"));
    tree_view->setObjectName(QString("ObjectTree"));
    tree_view->setContextMenuPolicy(Qt::CustomContextMenu);
    tree_view->setDragDropMode(QAbstractItemView::InternalMove);
    return tree_view;
}

SampleInfoStreamInterface *SampleViewComponents::createInfoStream(
        QWidget *parent)
{
    return new SampleInfoStreamInterface(parent);
}

