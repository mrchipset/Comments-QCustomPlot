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
    QCPAxisTicker::generate(range, locale, formatChar, precision,
                            ticks, subTicks, tickLabels);
}


double LarkAxisTicker::getTickStep(const QCPRange& range)
{
    return QCPAxisTicker::getTickStep(range);
}

int LarkAxisTicker::getSubTickCount(double tickStep)
{
    return 0;
}

QString LarkAxisTicker::getTickLabel(double tick, const QLocale& locale,
                                     QChar formatChar, int precision)
{
    return QCPAxisTicker::getTickLabel(tick, locale, formatChar, precision);
}

QVector<double> LarkAxisTicker::createTickVector(double tickStep,
        const QCPRange& range)
{
    return QCPAxisTicker::createTickVector(tickStep, range);
}

QVector<double> LarkAxisTicker::createSubTickVector(int subTickCount,
        const QVector<double>& ticks)
{
    return QCPAxisTicker::createSubTickVector(subTickCount, ticks);
}

QVector<QString> LarkAxisTicker::createLabelVector(const QVector<double>& ticks,
        const QLocale& locale, QChar formatChar, int precision)
{
    return QCPAxisTicker::createLabelVector(ticks, locale,
                                            formatChar, precision);
}