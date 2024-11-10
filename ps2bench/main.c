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

static char padBuf[256] __attribute__((aligned(64)));
struct padButtonStatus padData;
int port = 0, slot = 0;

static int waitPadReady(int port, int slot)
{
    int state;
    int lastState;
    char stateString[16];

    state = padGetState(port, slot);
    lastState = -1;
    while((state != PAD_STATE_STABLE) && (state != PAD_STATE_FINDCTP1)) {
        if (state != lastState) {
            padStateInt2String(state, stateString);
            scr_printf("Please wait, pad(%d,%d) is in state %s\n",
                       port, slot, stateString);
        }
        lastState = state;
        state=padGetState(port, slot);
    }
    // Were the pad ever 'out of sync'?
    if (lastState != -1) {
        printf("Pad OK!\n");
    }
    return 0;
}

void init_controller()
{
    SifInitRpc(0);
    SifLoadModule("rom0:SIO2MAN", 0, NULL);
    SifLoadModule("rom0:PADMAN", 0, NULL);
    padInit(0);
    printf("PortMax: %d\n", padGetPortMax());
    printf("SlotMax: %d\n", padGetSlotMax(port));
    padPortOpen(port, slot, &padBuf);
    waitPadReady(port,slot);
    padSetMainMode(port, slot, PAD_MMODE_DUALSHOCK, PAD_MMODE_LOCK);
    waitPadReady(port,slot);
    padEnterPressMode(port, slot);
}

int main()
{
    sleep(1);
    //Initialize controller library
    //init_controller();

    init_me_time();
    init_scr();
    scr_printf("Press X button to exit.\n");
    run_bench();


    

    while (1) 
    {
        //padRead(port, slot, &padData);
        //unsigned short pressed = padData.btns ^ 0xffff;
        //if (pressed == PAD_CROSS)
        //{
            scr_printf("pressed....\n");
            sleep(10);
            //break;
        //}
    }

    return 0;
}