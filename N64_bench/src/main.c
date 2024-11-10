#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdint.h>
#include <libdragon.h>
#include "bench.h"

int main(void)
{
    console_init();
    
    //debug_init_usblog();
    //console_set_debug(true);
    run_bench();
    printf("finished!\n");

    while(1) 
    {

    }
}