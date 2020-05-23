/*
 * main.c
 * platform NES game with vertcal scrolling
 * toasty <Tyler Morgan> May 2020
 */

#include "lib/neslib.h"
#include "lib/nesdoug.h"
#include "lib/defs.h"
#include "src/background.h"

void main(void)
{
	unsigned int scroll_y = 479;
	unsigned char frame = 0;
	unsigned char scroll_num = 0;
	ppu_off();
	pal_col(0, 0x0f);
	pal_col(1, 0x15);
	pal_col(2, 0x25);
	pal_col(3, 0x35);
	draw_bg();
	ppu_on_all();
	set_vram_buffer();

	//main game loop
	while(1) {
		scroll(0, scroll_y);
		frame++;
		if (frame == SCROLL_RATE) {
			scroll_num++;
			scroll_y--;
			frame = 0;
		}
		if (scroll_num == PLATFORM_DISTANCE<<3) {
			if (scroll_y > 256) {
				buffer_row(NAMETABLE_C, (char)((scroll_y- 0xff)>>3));
			} else {
				buffer_row(NAMETABLE_A, (char)scroll_y>>3);
			}
			scroll_num = 0;
		}
		
		ppu_wait_nmi();
		if (scroll_y == 0) {
			scroll_y = 479;
			frame = 0;
			scroll_num = 0;
		}
		clear_vram_buffer();
	}
}
