#include "LarkAxis.h"

LarkAxis::LarkAxis(QCPAxisRect* parent, AxisType type) : QCPAxis(parent, type),
    m_marginScaleMode(smNone),
    m_marginScale(std::make_pair(0.0, 0.0)),
    m_unitTextElement(new QCPTextElement(parent->parentPlot()))
{
    setupScaleStrategy();
    setupUnitLabel();
}

LarkAxis::~LarkAxis()
{
}

void LarkAxis::setMarginScaleMode(MarginScaleMode mode)
{
    m_marginScaleMode = mode;
}

LarkAxis::MarginScaleMode LarkAxis::marginScaleMode() const
{
    return m_marginScaleMode;
}

void LarkAxis::setMarginScale(const std::pair<double, double>& scale)
{
    m_marginScale = scale;
}

std::pair<double, double> LarkAxis::marginScale() const
{
    return m_marginScale;
}

void LarkAxis::setRange(const QCPRange& range)
{
    m_range = range;
    QCPRange _range = range;
    if (m_marginScaleMode != smNone) {
        if (m_marginScaleMode == smAbs) {
            _range.lower -= m_marginScale.first;
            _range.upper += m_marginScale.second;
        } else {
            // Check the scale
            if (abs(m_marginScale.first) < 1.0) {
                _range.lower -= m_marginScale.first * range.size();
            }
            if (abs(m_marginScale.second) < 1.0) {
                _range.upper += m_marginScale.second * range.size();
            }
        }
    }
    QCPAxis::setRange(_range);
}

void LarkAxis::setRange(double lower, double upper)
{
    QCPRange range(lower, upper);
    setRange(range);
}

void LarkAxis::setRangeLower(double lower)
{
    m_range.lower = lower;
    setRange(m_range);
}

void LarkAxis::setRangeUpper(double upper)
{
    m_range.upper = upper;
    setRange(m_range);
}

void LarkAxis::setUnitText(const QString& unit)
{
    m_unitTextElement->setText(unit);
}

QString LarkAxis::unitText() const
{
    return m_unitTextElement->text();
}

QCPTextElement* LarkAxis::unitLabel()
{
    return m_unitTextElement;
}


void LarkAxis::setupScaleStrategy()
{
    switch (axisType()) {
    case QCPAxis::atLeft:
    case QCPAxis::atRight:
        m_marginScaleMode = smFactor;
        m_marginScale = std::make_pair(0.0, 0.1);
        break;
    case QCPAxis::atBottom:
    case QCPAxis::atTop:
    default:
        m_marginScaleMode = smNone;
        m_marginScale = std::make_pair(0.0, 0.0);
        break;
    }
}

void LarkAxis::setupUnitLabel()
{
    auto pAxisRect = axisRect();
    if (pAxisRect == nullptr) {
        return;
    }
    Qt::Alignment alignment;
    switch (axisType()) {
    case QCPAxis::atLeft:
        alignment = Qt::AlignLeft | Qt::AlignTop;
        break;
    case QCPAxis::atRight:
        alignment = Qt::AlignRight | Qt::AlignTop;
        break;
    case QCPAxis::atBottom:
        alignment = Qt::AlignRight | Qt::AlignBottom;
        break;
    case QCPAxis::atTop:
        alignment = Qt::AlignRight | Qt::AlignTop;
        break;
    default:
        alignment = Qt::AlignRight | Qt::AlignTop;
        break;
    }
    pAxisRect->insetLayout()->addElement(m_unitTextElement, alignment);

}