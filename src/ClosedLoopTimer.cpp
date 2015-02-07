#include "ClosedLoopTimer.h"

ClosedLoopTimer::ClosedLoopTimer(QObject *parent) :
    QTimer(parent)
{
}


void ClosedLoopTimer::startClosedLoop( int msec )
{
    this->setSingleShot( true );
    this->start( msec );

    while ( this->isActive() )
    {
        qApp->processEvents();
    }
}


void ClosedLoopTimer::startClosedLoop( int msec,  bool (*feedback_func)() )
{
    this->setSingleShot( true );
    this->start( msec );

    while ( this->isActive() )
    {
        if ( (*feedback_func)() )
        {
            this->stop();
        }
        qApp->processEvents();
    }
}
