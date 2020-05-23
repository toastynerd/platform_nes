/*
 * background.c
 * functions related to drawing and generating the background
 * platfrom nes game with vertical scrolling
 * toasty <Tyler Morgan May 2020
 */

#include "background.h"
#include "../lib/neslib.h"
#include "../lib/nesdoug.h"
#include "../lib/defs.h"

const unsigned char blank_row[] = {
BLANK_TILE,
BLANK_TILE,
BLANK_TILE,
BLANK_TILE,
BLANK_TILE,
BLANK_TILE,
BLANK_TILE,
BLANK_TILE,
BLANK_TILE,
BLANK_TILE,
BLANK_TILE,
BLANK_TILE,
BLANK_TILE,
BLANK_TILE,
BLANK_TILE,
BLANK_TILE,
BLANK_TILE,
BLANK_TILE,
BLANK_TILE,
BLANK_TILE,
BLANK_TILE,
BLANK_TILE,
BLANK_TILE,
BLANK_TILE,
BLANK_TILE,
BLANK_TILE,
BLANK_TILE,
BLANK_TILE,
BLANK_TILE,
BLANK_TILE,
BLANK_TILE,
BLANK_TILE
};

void __fastcall__ draw_bg(void)
{
	char y, i;
	i = 0;
	for (y = 32; y > 0; y--) {
		if (i == PLATFORM_DISTANCE || y == 0) {
			draw_row(NAMETABLE_C, y);
			i = 0;
		}
		i++;
	}
	i = 0;
	for (y = 32; y > 0; y--) {
		if (i == PLATFORM_DISTANCE || y == 0) {
			draw_row(NAMETABLE_A, y);
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

void __fastcall__ buffer_platform(unsigned int start_address, char length)
{
	char i;
	one_vram_buffer(PLATFORM_LEFT_CAP, start_address);
	for (i = 1; i < length; i++) {
		one_vram_buffer(PLATFORM_CENTER, start_address + i);
	}
	one_vram_buffer(PLATFORM_RIGHT_CAP, start_address + i);
}

void __fastcall__ draw_row(unsigned int nametable, char row)
{
	//left side of the screen
	draw_platform(NTADR(nametable, rand16() & 0x07, row), (rand16() ) & 0x7);

	//right side of screen
	draw_platform(NTADR(nametable, (rand16()|0x10) & 0x17, row), (rand16() ) & 0x7);

}


void __fastcall__ buffer_row(unsigned int nametable, char row)
{
	clear_row(nametable, row);
	//left side of the screen
	buffer_platform(NTADR(nametable, (rand16() | 0x1) & 0x07, row), (rand16() ) & 0x7);

	//right side of screen
	buffer_platform(NTADR(nametable, (rand16()|0x10) & 0x17, row), (rand16() ) & 0x7);

}

void __fastcall__ clear_row(unsigned int nametable, char row)
{
	multi_vram_buffer_horz(blank_row, 32, NTADR(nametable, 0, row));
}
