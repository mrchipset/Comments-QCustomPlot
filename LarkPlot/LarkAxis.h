#ifndef LARK_AXIS_H
#define LARK_AXIS_H

#include "api.h"

#include "qcustomplot.h"
#include <utility>

/* TODO
 * Rewrite the AxisTicker for scientific numbers
 * Add some helper method for preference and information
 */
class LARK_API LarkAxis : public QCPAxis
{
    Q_OBJECT
    Q_PROPERTY(QString unit READ unitText WRITE setUnitText)
public:
    enum MarginScaleMode {
        smNone,
        smFactor,
        smAbs
    };
    Q_ENUMS(MarginScaleMode);
public:
    explicit LarkAxis(QCPAxisRect* parent, AxisType type);
    virtual ~LarkAxis();

    void setMarginScaleMode(MarginScaleMode mode);
    MarginScaleMode marginScaleMode() const;
    void setMarginScale(const std::pair<double, double>& scale);
    std::pair<double, double> marginScale() const;
    Q_SLOT virtual void setRange(const QCPRange& range) override;
    void setRange(double lower, double upper);
    virtual void setRangeLower(double lower) override;
    virtual void setRangeUpper(double upper) override;

    void setUnitText(const QString& unit);
    QString unitText() const;
    QCPTextElement* unitLabel();
protected:
    std::pair<double, double> m_marginScale;
    MarginScaleMode m_marginScaleMode;
    QCPRange m_range;   ///< The origin range set by user/algorithm
    QCPTextElement* m_unitTextElement;  ///< unit element
    /**
     * @brief The method to setup the strategy to rescale the range;
     * Please override this method to match your demand.
     */
    virtual void setupScaleStrategy();
    virtual void setupUnitLabel();
};


#endif