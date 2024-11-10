/*
 * PSP Software Development Kit - https://github.com/pspdev
 * -----------------------------------------------------------------------
 * Licensed under the BSD license, see LICENSE in PSPSDK root for details.
 *
 * main.c - Basic sample to demonstrate the kprintf handler.
 *
 * Copyright (c) 2005 Marcus R. Brown <mrbrown@ocgnet.org>
 * Copyright (c) 2005 James Forshaw <tyranid@gmail.com>
 * Copyright (c) 2005 John Kelley <ps2dev@kelley.ca>
 *
 */
#include <psptypes.h>
#include <pspkernel.h>
#include <pspdebug.h>
#include <psputils.h>
#include "include/benchmark.h"

PSP_MODULE_INFO("KPTEST", 0x1000, 1, 1);
/* Define the main thread's attribute value (optional) */
PSP_MAIN_THREAD_ATTR(0);

/* Define printf, just to make typing easier */
#define printf	pspDebugScreenPrintf


int main(void)
{
	pspDebugScreenInit();
  
    run_bench();
	
    
	printf("benchmark beendet:\n\n");
    while(1)
    {
        
        
    }
    sceKernelExitGame();
	return 0;
}