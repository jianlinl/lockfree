#ifndef TIMER_H
#define TIMER_H

#include <sys/time.h>
class Timer{
public:
    Timer();
    void Start();
    void Stop();
    void Reset();
    void Cost_time();
private:
    struct timeval t1;
    struct timeval t2;
    bool b1,b2;
};

#endif //TIMER_H
