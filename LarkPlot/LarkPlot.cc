#include "LarkPlot.h"
#include "LarkSelectionRect.h"
#include "LarkAxisRect.h"
#include "LarkGraph.h"

LarkPlot::LarkPlot(QWidget* parent) : QCustomPlot(parent)
{
    initializePlot();
}

LarkPlot::~LarkPlot()
{

}

void LarkPlot::setContextMenuPolicy(Qt::ContextMenuPolicy policy)
{
    QCustomPlot::setContextMenuPolicy(policy);
    m_contextMenuPolicy = policy;
}

void LarkPlot::initializePlot()
{
    // Change the Selection Rect to Lark customized.
    // Comment this when using the revised QCustomPlot
    // setSelectionRect(new LarkSelectionRect(this));

    // Substate the default Axis rectangle.
    createDefaultLarkAxisRect();

}

void LarkPlot::createDefaultLarkAxisRect()
{
    if (axisRect() != nullptr) {
        mPlotLayout->remove(axisRect());
    }
    QCPAxisRect* defaultAxisRect = new LarkAxisRect(this, true);
    mPlotLayout->addElement(0, 0, defaultAxisRect);
    xAxis = defaultAxisRect->axis(QCPAxis::atBottom);
    yAxis = defaultAxisRect->axis(QCPAxis::atLeft);
    xAxis2 = defaultAxisRect->axis(QCPAxis::atTop);
    yAxis2 = defaultAxisRect->axis(QCPAxis::atRight);
    legend = new QCPLegend;
    legend->setVisible(false);
    defaultAxisRect->insetLayout()->addElement(legend, Qt::AlignRight | Qt::AlignTop);
    defaultAxisRect->insetLayout()->setMargins(QMargins(12, 12, 12, 12));

    defaultAxisRect->setLayer(QLatin1String("background"));
    xAxis->setLayer(QLatin1String("axes"));
    yAxis->setLayer(QLatin1String("axes"));
    xAxis2->setLayer(QLatin1String("axes"));
    yAxis2->setLayer(QLatin1String("axes"));
    xAxis->grid()->setLayer(QLatin1String("grid"));
    yAxis->grid()->setLayer(QLatin1String("grid"));
    xAxis2->grid()->setLayer(QLatin1String("grid"));
    yAxis2->grid()->setLayer(QLatin1String("grid"));
    legend->setLayer(QLatin1String("legend"));
}

LarkGraph* LarkPlot::addGraph(const QString& title, QCPAxis* keyAxis, QCPAxis* valueAxis)
{
    LarkGraph* newGraph = nullptr;

    if (!keyAxis) keyAxis = xAxis;
    if (!valueAxis) valueAxis = yAxis;
    if (!keyAxis || !valueAxis) {
        qDebug() << Q_FUNC_INFO << "can't use default QCustomPlot xAxis or yAxis, because at least one is invalid (has been deleted)";
        return nullptr;
    }
    if (keyAxis->parentPlot() != this || valueAxis->parentPlot() != this) {
        qDebug() << Q_FUNC_INFO << "passed keyAxis or valueAxis doesn't have this QCustomPlot as parent";
        return nullptr;
    }

    newGraph = new LarkGraph(keyAxis, valueAxis);
    newGraph->setName(title);
    return newGraph;
}


void LarkPlot::mouseReleaseEvent(QMouseEvent* event)
{
    // Check the mouse moved, and disable the context menu
    if (event->button() == Qt::RightButton) {
        if (!mMouseHasMoved) {
            QCustomPlot::setContextMenuPolicy(m_contextMenuPolicy);
        } else {
            QCustomPlot::setContextMenuPolicy(Qt::NoContextMenu);
        }
    }

    QCustomPlot::mouseReleaseEvent(event);
}

void LarkPlot::keyPressEvent(QKeyEvent* event)
{
    // event->accept();
}

void LarkPlot::keyReleaseEvent(QKeyEvent* event)
{
    switch (event->key()) {
    case Qt::Key_Home:
        rescaleAxes(true);
        replot(rpQueuedReplot);
        break;
    default:
        event->ignore();
        break;
    }
    event->accept();
}