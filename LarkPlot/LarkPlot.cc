#include "LarkPlot.h"
#include "LarkSelectionRect.h"

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
    //Comment this when using the revised QCustomPlot
    // setSelectionRect(new LarkSelectionRect(this));

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