#include <QTimer>
#include <QPaintEvent>
#include <QPainter>
#include "./transitioncolorwidget.hpp"

#define DELTA_TIME 30

TransitionColorWidget::TransitionColorWidget(const QColor &startColor,
                                             const QColor &endColor,
                                             int duration,
                                             QWidget *parent):
    QWidget(parent),
    m_timer(new QTimer(this)),
    m_currentColor(startColor),
    m_endColor(endColor),
    m_duration(duration),

    m_unit((endColor - startColor).normalized()),
    m_length((endColor - startColor).length()),
    m_remainingTime(duration)
{
    connect(m_timer, SIGNAL(timeout()), SLOT(tick()));
    m_timer->start(DELTA_TIME);
}

void TransitionColorWidget::tick()
{
    if (m_remainingTime > 0) {
        repaint();
        nextColor(DELTA_TIME);
        m_remainingTime -= DELTA_TIME;
    }
}

void TransitionColorWidget::nextColor(int dtime)
{
    qreal d = static_cast<qreal>(dtime) / m_duration;
    m_currentColor += m_unit * (m_length * d);
}

void TransitionColorWidget::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    painter.fillRect(0, 0, width(), height(), m_currentColor);
}
