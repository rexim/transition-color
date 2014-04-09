#include "./transitioncolorengine.hpp"

TransitionColorEngine::TransitionColorEngine(const QColor &currentColor,
                                             QObject *parent):
    QObject(parent),
    m_currentColor(currentColor),
    m_targetColor(currentColor),
    m_duration(0),
    m_remainingTime(0)
{}

void TransitionColorEngine::transitionTo(const QColor &targetColor, int duration)
{
    m_duration      = duration;
    m_remainingTime = duration;
    m_targetColor   = targetColor;
    m_unit          = (m_targetColor - m_currentColor).normalized();
    m_length        = (m_targetColor - m_currentColor).length();
}

void TransitionColorEngine::tick(int deltaTime)
{
    if (m_remainingTime > 0) {
        m_remainingTime -= deltaTime;

        qreal d = static_cast<qreal>(deltaTime) / m_duration;
        m_currentColor += m_unit * (m_length * d);
        emit currentColorChanged(m_currentColor);
    }
}
