#ifndef LARK_AXIS_H
#define LARK_AXIS_H

#include "api.h"

#include "qcustomplot.h"

/* TODO
 * Inherit the QCPAxis and Enable the Axis with unit label
 * Hide the original setRange function and add auto enlarge function.
 */
class LARK_API LarkAxis : public QCPAxis
{
public:
    explicit LarkAxis(QCPAxisRect* parent, AxisType type);
    ~LarkAxis();
};



#endif