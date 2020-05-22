/*
 * background.c
 * functions related to drawing and generating the background
 * platfrom nes game with vertical scrolling
 * toasty <Tyler Morgan May 2020
 */

#include "background.h"
#include "../lib/neslib.h"
#include "../lib/defs.h"

void __fastcall__ draw_bg(void)
{
	draw_platform(NTADR_A(10, 10), 5);
}

void __fastcall__ draw_platform(unsigned int start_address, char length)
{
	char i;
	vram_adr(start_address);
	vram_put(PLATFORM_LEFT_CAP);
	for (i = 1; i < length; i++) {
		vram_put(PLATFORM_CENTER);
	}
	vram_put(PLATFORM_RIGHT_CAP);
}
