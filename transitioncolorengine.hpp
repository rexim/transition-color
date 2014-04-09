#ifndef TRANSITIONCOLORENGINE_HPP_
#define TRANSITIONCOLORENGINE_HPP_

#include <QColor>
#include <QObject>

#include "./colorvector.hpp"

class TransitionColorEngine: public QObject
{
    Q_OBJECT
public:
    TransitionColorEngine(const QColor &currentColor = QColor(),
                          QObject *parent = 0);

public slots:
    void transitionTo(const QColor &targetColor, int duration);
    void tick(int deltaTime);

signals:
    void currentColorChanged(const QColor &currentColor);

private:
    QColor m_currentColor;
    QColor m_targetColor;
    int m_duration;
    int m_remainingTime;

    ColorVector m_unit;
    qreal m_length;
};

#endif  // TRANSITIONCOLORENGINE_HPP_
