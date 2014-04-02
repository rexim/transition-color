#include "./colortransitor.hpp"

ColorTransitor::ColorTransitor(const QColor &currentColor,
                               QObject *parent):
    QObject(parent),
    m_currentColor(currentColor),
    m_finalColor(currentColor),
    m_duration(0),
    m_remainingTime(0)
{}

void ColorTransitor::transitionTo(const QColor &color, int duration)
{
    m_duration      = duration;
    m_remainingTime = duration;
    m_finalColor    = color;
    m_unit          = (m_finalColor - m_currentColor).normalized();
    m_length        = (m_finalColor - m_currentColor).length();
}

void ColorTransitor::tick(int deltaTime)
{
    if (m_remainingTime > 0) {
        m_remainingTime -= deltaTime;

        qreal d = static_cast<qreal>(deltaTime) / m_duration;
        m_currentColor += m_unit * (m_length * d);
        emit currentColorChanged(m_currentColor);
    }
}
