#ifndef TRANSITIONCOLORWIDGET_HPP_
#define TRANSITIONCOLORWIDGET_HPP_

#include <QWidget>
#include "./colorvector.hpp"

class QTimer;
class QPaintEvent;

class TransitionColorWidget: public QWidget
{
    Q_OBJECT
public:
    TransitionColorWidget(const QColor &startColor,
                          const QColor &endColor,
                          int duration,
                          QWidget *parent = 0);

protected:
    void paintEvent(QPaintEvent * event) override;

private slots:
    void tick();

private:
    void nextColor(int dtime);

private:
    QTimer *m_timer;
    QColor m_currentColor;
    QColor m_endColor;
    int m_duration;

    ColorVector m_unit;
    qreal m_length;
    int m_remainingTime;
};

#endif  // TRANSITIONCOLORWIDGET_HPP_
