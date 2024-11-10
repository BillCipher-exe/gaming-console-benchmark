#define _EE

#include "include/me_timer.h"
#include <tamtypes.h>
#include <timer.h>

u64 timer_start_time;
u64 timer_stop_time;
u32 time_ms;
//init the timer
void init_me_time()
{
    InitTimer(0);
}

void start_timer()
{
    timer_start_time = GetTimerSystemTime();
}

u32 stop_timer()
{
    timer_stop_time = GetTimerSystemTime();
    u64 time_difference= timer_stop_time-timer_start_time;
    time_ms = time_difference/(kBUSCLK/1000);

    return time_ms;
}