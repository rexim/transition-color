#include "./timerwithdeltatime.hpp"

TimerWithDeltaTime::TimerWithDeltaTime(QObject *parent):
    QTimer(parent)
{
    connect(this, SIGNAL(timeout()), SLOT(emitTimeoutWithDeltaTime()));
}

void TimerWithDeltaTime::emitTimeoutWithDeltaTime()
{
    emit timeout(interval());
}
