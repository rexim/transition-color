#ifndef TIMERWITHDELTATIME_HPP_
#define TIMERWITHDELTATIME_HPP_

#include <QTimer>

class TimerWithDeltaTime: public QTimer
{
    Q_OBJECT
public:
    TimerWithDeltaTime(QObject *parent = 0);

signals:
    void timeout(int deltaTime);

private slots:
    void emitTimeoutWithDeltaTime();
};

#endif  // TIMERWITHDELTATIME_HPP_
