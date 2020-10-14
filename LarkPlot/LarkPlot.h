#ifndef LARK_PLOT_H
#define LARK_PLOT_H

#include "api.h"

#include "qcustomplot.h"

#include <QList>

class LarkGraph;

class LARK_API LarkPlot : public QCustomPlot
{
    Q_OBJECT
public:
    explicit LarkPlot(QWidget* parent = nullptr);
    ~LarkPlot();
    void setContextMenuPolicy(Qt::ContextMenuPolicy policy);
    LarkGraph* addGraph(const QString& title,
                        QCPAxis* keyAxis = nullptr, QCPAxis* valueAxis = nullptr);
private:
    QList<QCPSelectionRect*> m_selectionRects;
    Qt::ContextMenuPolicy m_contextMenuPolicy;
    void initializePlot();
    void createDefaultLarkAxisRect();
protected:
    //QT Events

    virtual void mouseReleaseEvent(QMouseEvent* event) override;
    virtual void keyPressEvent(QKeyEvent* event) override;
    virtual void keyReleaseEvent(QKeyEvent* event) override;

};
#endif