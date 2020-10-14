#ifndef LARK_GRAPH_H
#define LARK_GRAPH_H

#include "api.h"

#include "qcustomplot.h"

class LARK_API LarkGraph : public QCPGraph
{
    Q_OBJECT
public:
    explicit LarkGraph(QCPAxis* keyAxis, QCPAxis* valueAxis);
    virtual ~LarkGraph();
};

#endif