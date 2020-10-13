#ifndef LARK_PLOT_H
#define LARK_PLOT_H

#include "api.h"

#include "qcustomplot.h"

#include <QList>

class LARK_API LarkPlot : public QCustomPlot
{
    Q_OBJECT
public:
    explicit LarkPlot(QWidget* parent = nullptr);
    ~LarkPlot();
    void setContextMenuPolicy(Qt::ContextMenuPolicy policy);
private:
    QList<QCPSelectionRect*> m_selectionRects;
    Qt::ContextMenuPolicy m_contextMenuPolicy;
    void initializePlot();
protected:
    virtual void mouseReleaseEvent(QMouseEvent* event) override;
};
#endif