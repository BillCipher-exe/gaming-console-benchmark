#ifndef ME_TIMER_H
#define ME_TIMER_H
#include <tamtypes.h>

extern u64 timer_start_time;
extern u64 timer_stop_time;
extern u32 time_ms;

void init_me_time();
void start_timer();
u32 stop_timer();

#endif // ME_TIMER_H