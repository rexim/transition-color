#ifndef COLORTRANSITOR_HPP_
#define COLORTRANSITOR_HPP_

#include <QColor>
#include <QObject>

#include "./colorvector.hpp"

class ColorTransitor: public QObject
{
    Q_OBJECT
public:
    ColorTransitor(const QColor &currentColor,
                   QObject *parent = 0);

public slots:
    void transitionTo(const QColor &color, int duration);
    void tick(int deltaTime);

signals:
    void currentColorChanged(const QColor &currentColor);

private:
    QColor m_currentColor;
    QColor m_finalColor;
    int m_duration;
    int m_remainingTime;

    ColorVector m_unit;
    qreal m_length;
};

#endif  // COLORTRANSITOR_HPP_