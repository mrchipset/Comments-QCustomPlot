#include "LarkColorMap.h"

LarkColorMapData::LarkColorMapData(int keySize, int valueSize,
                                   const QCPRange& keyRange,
                                   const QCPRange& valueRange)
    : QCPColorMapData(keySize, valueSize, keyRange, valueRange)
{

}

LarkColorMapData::~LarkColorMapData()
{
    if (mData)
        delete[] mData;
    if (mAlpha)
        delete[] mAlpha;
}

LarkColorMapData::LarkColorMapData(const LarkColorMapData& other)
    : QCPColorMapData(other)
{
    *this = other;
}

LarkColorMapData& LarkColorMapData::operator=(const LarkColorMapData& other)
{
    if (&other != this) {
        const int keySize = other.keySize();
        const int valueSize = other.valueSize();
        if (!other.mAlpha && mAlpha)
            clearAlpha();
        setSize(keySize, valueSize);
        if (other.mAlpha && !mAlpha)
            createAlpha(false);
        setRange(other.keyRange(), other.valueRange());
        if (!isEmpty()) {
            memcpy(mData, other.mData, sizeof(mData[0])*keySize * valueSize);
            if (mAlpha)
                memcpy(mAlpha, other.mAlpha, sizeof(mAlpha[0])*keySize * valueSize);
        }
        mDataBounds = other.mDataBounds;
        mDataModified = true;
    }
    return *this;
}


LarkColorMap::LarkColorMap(QCPAxis* keyAxis, QCPAxis* valueAxis) :
    QCPColorMap(keyAxis, valueAxis)
{
    if (mMapData) {
        delete mMapData;
    }
    mMapData = new LarkColorMapData(10, 10, QCPRange(0, 5), QCPRange(0, 5));
}

LarkColorMap::~LarkColorMap()
{
}