#ifndef LARK_COLOR_MAP_H
#define LARK_COLOR_MAP_H

#include "api.h"

#include "qcustomplot.h"

/* NOTICE
 * Inherit the library in order to meet specific requirement
 */

/**
 * @brief
 *
 */
class LARK_API LarkColorMapData : public QCPColorMapData
{
public:
    LarkColorMapData(int keySize, int valueSize, const QCPRange& keyRange, const QCPRange& valueRange);
    ~LarkColorMapData();
    LarkColorMapData(const LarkColorMapData& other);
    LarkColorMapData& operator=(const LarkColorMapData& other);
};


class LARK_API LarkColorMap : public QCPColorMap
{
public:
    explicit LarkColorMap(QCPAxis* keyAxis, QCPAxis* valueAxis);
    virtual ~LarkColorMap();
};

#endif