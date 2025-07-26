#include <pspmoduleinfo.h>

#include "pspdisplay.h"
#include "pspkernel.h"
#include "stdlib.h"
#include "stdio.h"
//#include "include/hook.h"
#include "include/blit.h"

#ifndef MAJOR_VERSION
#define MAJOR_VERSION 0
#endif

#ifndef MINOR_VERSION
#define MINOR_VERSION 0
#endif

PSP_MODULE_INFO("myhud", PSP_MODULE_KERNEL, MAJOR_VERSION, MINOR_VERSION);

int appMainThread(unsigned int args, void* argp) {
    sceKernelDelayThread(1000000);
    int x = 0;
    int y = 0;
    int number = 24;
    char msg[16];
    while(1) {
        sceKernelDelayThreadCB(200);
        sprintf(msg, "Test: %d", number);
        blit_string(x, y, msg, 0xFFFFFF, 0x000000);
        sceDisplayWaitVblankStart();
    }
    sceKernelExitDeleteThread(0);
    return 0;
}

void gui_thread(unsigned int args, void *argp) {
    int thid = sceKernelCreateThread("app_main_thread", appMainThread, 0x10, 0x200, 0, NULL);
    if (thid >= 0) {
        sceKernelStartThread(thid, args, argp);
    }
}

int module_start(SceSize args, void *argp) {

    gui_thread(args, argp);

    return 0;
}

int module_stop(SceSize args, void *argp) {
    
    return 0;
}
