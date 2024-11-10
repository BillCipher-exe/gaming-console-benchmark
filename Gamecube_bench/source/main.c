#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <malloc.h>
#include <ogcsys.h>
#include <gccore.h>
#include <ogc/lwp_watchdog.h>

#define FLOP_COUNT 1000000000  // Number of iterations

static void *xfb = NULL;
static GXRModeObj *rmode = NULL;

void * Initialise() {

	void *framebuffer;

	VIDEO_Init();
	PAD_Init();
	
	rmode = VIDEO_GetPreferredMode(NULL);

	framebuffer = MEM_K0_TO_K1(SYS_AllocateFramebuffer(rmode));
	console_init(framebuffer,20,20,rmode->fbWidth,rmode->xfbHeight,rmode->fbWidth*VI_DISPLAY_PIX_SZ);
	
	VIDEO_Configure(rmode);
	VIDEO_SetNextFramebuffer(framebuffer);
	VIDEO_SetBlack(FALSE);
	VIDEO_Flush();
	VIDEO_WaitVSync();
	if(rmode->viTVMode&VI_NON_INTERLACE) VIDEO_WaitVSync();

	return framebuffer;

}


int main(int argc, char **argv) {

	xfb = Initialise();

	run_bench();

	
	while(1) {

		VIDEO_WaitVSync();
	}

	return 0;
}