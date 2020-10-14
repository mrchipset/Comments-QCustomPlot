#ifndef LARK_AXIS_TICKER_H
#define LARK_AXIS_TICKER_H

#include "api.h"

#include "LarkAxis.h"

/* TODO
 * 1. overwrite the generate method to generate sceintific axis
 */
class LARK_API LarkAxisTicker : public QCPAxisTicker
{
    Q_GADGET
public:
    LarkAxisTicker();
    ~LarkAxisTicker();

    virtual void generate(const QCPRange& range, const QLocale& locale,
                          QChar formatChar, int precision,
                          QVector<double>& ticks, QVector<double>* subTicks,
                          QVector<QString>* tickLabels) override;

protected:
    virtual double getTickStep(const QCPRange& range) override;
    virtual int getSubTickCount(double tickStep) override;
    virtual QString getTickLabel(double tick, const QLocale& locale,
                                 QChar formatChar, int precision) override;
    virtual QVector<double> createTickVector(double tickStep,
            const QCPRange& range) override;
    virtual QVector<double> createSubTickVector(int subTickCount,
            const QVector<double>& ticks) override;
    virtual QVector<QString> createLabelVector(const QVector<double>& ticks,
            const QLocale& locale, QChar formatChar, int precision) override;


};




#endif