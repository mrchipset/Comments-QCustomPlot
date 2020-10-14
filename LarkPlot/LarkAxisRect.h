#ifndef LARK_AXIS_RECT_H
#define LARK_AXIS_RECT_H

#include "api.h"

#include "qcustomplot.h"
#include "LarkAxis.h"

class LARK_API LarkAxisRect : public QCPAxisRect
{
    Q_OBJECT
public:
    explicit LarkAxisRect(QCustomPlot* parentPlot, bool setupDefaultAxes = true);
    virtual QCPAxis* addAxis(QCPAxis::AxisType type, QCPAxis* axis = 0) override;
private:
    Q_DISABLE_COPY(LarkAxisRect)

    friend class QCustomPlot;
};


#endif