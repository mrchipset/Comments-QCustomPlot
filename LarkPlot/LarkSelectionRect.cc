#include "LarkSelectionRect.h"
#include <QMouseEvent>

LarkSelectionRect::LarkSelectionRect(QCustomPlot* parent) : QCPSelectionRect(parent)
{

}

void LarkSelectionRect::startSelection(QMouseEvent* event)
{
    if (event->button() & Qt::LeftButton) {
        QCPSelectionRect::startSelection(event);
    } else {
        cancel();
    }
}

// void LarkSelectionRect::endSelection(QMouseEvent* event)
// {
//     if (mActive) {
//         QCPSelectionRect::endSelection(event);
//     } else {
//         cancel();
//     }
// }