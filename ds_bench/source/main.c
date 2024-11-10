#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <nds.h>
#include "bench.h"



int main(int argc, char **argv)
{
    PrintConsole topScreen;
    videoSetMode(MODE_0_2D);
    videoSetModeSub(MODE_0_2D);
    vramSetBankA(VRAM_A_MAIN_BG);
    vramSetBankC(VRAM_C_SUB_BG);

    consoleInit(&topScreen, 3, BgType_Text4bpp, BgSize_T_256x256, 31, 0, true, true);

    consoleSelect(&topScreen);
    printf("bench START:\n");
    run_bench();
    printf("Benchmark finished\n");
    while (1)
    {
        swiWaitForVBlank();
    }

    return 0;
}