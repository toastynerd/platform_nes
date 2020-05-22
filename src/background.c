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
	char y, i;
	i = 0;
	for (y = 0; y < 32; y ++) {
		if (i == PLATFORM_DISTANCE || y == 0) {
			draw_row(y);
			i = 0;
		}
		i++;
	}
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

void __fastcall__ draw_row(char row)
{
	//left side of the screen
	draw_platform(NTADR_A(rand16() & 0x0f, row), rand16() & 0x7);
	draw_platform(NTADR_C(rand16() & 0x0f, row), rand16() & 0x7);

	//right side of screen
	draw_platform(NTADR_A((rand16()|0x10) & 0x1f, row), rand16() & 0x7);
	draw_platform(NTADR_C((rand16()|0x10) & 0x1f, row), rand16() & 0x7);

}
