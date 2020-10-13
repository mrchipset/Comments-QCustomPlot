#ifndef LARK_PLOT_SELCTION_RECT_H
#define LARK_PLOT_SELCTION_RECT_H

#include "api.h"

#include "LarkPlot.h"

/**
 * @brief LarkSelectionRect is inherited from QCPSelectionRect
 *
 * This is a customized QCPSelectionRect, in order to check the mouse button is
 * LeftButton.
 */
class LARK_API LarkSelectionRect : public QCPSelectionRect
{
    Q_OBJECT
public:
    explicit LarkSelectionRect(LarkPlot* parent);

protected:
    virtual void startSelection(QMouseEvent* event) override;
    // virtual void endSelection(QMouseEvent* event) override;
};
#endif