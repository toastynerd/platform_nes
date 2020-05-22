/*
 * main.c
 * platform NES game with vertcal scrolling
 * toasty <Tyler Morgan> May 2020
 */

#include "lib/neslib.h"
#include "lib/defs.h"
#include "src/background.h"

void main(void)
{
	unsigned int scroll_y = 479;
	unsigned char frame = 0;
	ppu_off();
	pal_col(0, 0x0f);
	pal_col(1, 0x15);
	pal_col(2, 0x25);
	pal_col(3, 0x35);
	draw_bg();
	ppu_on_all();

	//main game loop
	while(1) {
		scroll(0, scroll_y);
		frame++;
		if (frame == SCROLL_RATE) {
			scroll_y--;
			frame = 0;
		}
		if (scroll_y == 0) {
			scroll_y = 479;
		}
		ppu_wait_frame();
	}
}
