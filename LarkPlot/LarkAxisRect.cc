#include "LarkAxisRect.h"

LarkAxisRect::LarkAxisRect(QCustomPlot* parentPlot, bool setupDefaultAxes) :
    QCPAxisRect(parentPlot, false)
{
    if (setupDefaultAxes) {
        QCPAxis* xAxis = addAxis(QCPAxis::atBottom);
        QCPAxis* yAxis = addAxis(QCPAxis::atLeft);
        QCPAxis* xAxis2 = addAxis(QCPAxis::atTop);
        QCPAxis* yAxis2 = addAxis(QCPAxis::atRight);
        setRangeDragAxes(xAxis, yAxis);
        setRangeZoomAxes(xAxis, yAxis);
        xAxis2->setVisible(false);
        yAxis2->setVisible(false);
        xAxis->grid()->setVisible(true);
        yAxis->grid()->setVisible(true);
        xAxis2->grid()->setVisible(false);
        yAxis2->grid()->setVisible(false);
        xAxis2->grid()->setZeroLinePen(Qt::NoPen);
        yAxis2->grid()->setZeroLinePen(Qt::NoPen);
        xAxis2->grid()->setVisible(false);
        yAxis2->grid()->setVisible(false);
    }
}

QCPAxis* LarkAxisRect::addAxis(QCPAxis::AxisType type, QCPAxis* axis)
{
    QCPAxis* newAxis = axis;
    if (newAxis == nullptr) {
        newAxis = new LarkAxis(this, type);
    }
    return QCPAxisRect::addAxis(type, newAxis);
}
