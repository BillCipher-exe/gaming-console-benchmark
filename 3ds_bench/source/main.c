#include <3ds.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>
#include "bench.h"

int main(int argc, char **argv)
{
	// Initialize services
	gfxInitDefault();
	//Initialize console on top screen. Using NULL as the second argument tells the console library to use the internal console structure as current one
	consoleInit(GFX_TOP, NULL);

	run_bench();
	
	// Main loop
	while (aptMainLoop())
	{

		

		gfxFlushBuffers();
		gfxSwapBuffers();
		gspWaitForVBlank();
	}

	// Exit services
	gfxExit();

	return 0;
}