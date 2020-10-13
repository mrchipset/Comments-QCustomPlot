#ifndef LARK_PLOT_H
#define LARK_PLOT_H

#include "api.h"

#include "qcustomplot.h"

/* TODO
 * 1. Custom the selection mode
 * 2. Change the ContextMenu, don't display when mouse moved.
 */
class API LarkPlot : public QCustomPlot
{
    Q_OBJECT
    explicit LarkPlot(QWidget* parent = nullptr);
    ~LarkPlot();
};
#endif