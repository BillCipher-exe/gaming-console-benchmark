#include <tamtypes.h>
#include <stdio.h>
#include <kernel.h>
#include <sifrpc.h>
#include <graph.h>
#include <debug.h>
#include <libpad.h>
#include <unistd.h>
#include <loadfile.h>
#include <math.h>

#include "include/me_timer.h"
#include "include/benchmark.h"


int main()
{
    sleep(1);
    init_me_time();
    init_scr();
    
    run_bench();
    scr_printf("benchmark finished.\n");

    

    while (1) 
    {
            sleep(10);
    }

    return 0;
}
