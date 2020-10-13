#include "LarkAxisTicker.h"

LarkAxisTicker::LarkAxisTicker() : QCPAxisTicker()
{
}

LarkAxisTicker::~LarkAxisTicker()
{
}

void LarkAxisTicker::generate(const QCPRange& range, const QLocale& locale,
                              QChar formatChar, int precision,
                              QVector<double>& ticks, QVector<double>* subTicks,
                              QVector<QString>* tickLabels)
{

}

QVector<QString> LarkAxisTicker::createLabelVector(const QVector<double>& ticks,
        const QLocale& locale, QChar formatChar, int precision)
{

}