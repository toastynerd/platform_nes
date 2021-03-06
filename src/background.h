/*
 * background.h
 * functions related to drawing the background
 * platform nes game with vertical scrolling
 * toasty <Tyler Morgan> May 2020
 */

void __fastcall__ draw_bg(void);
void __fastcall__ draw_platform(unsigned int start_address, char length);
void __fastcall__ draw_row(unsigned int nametable, char row);
void __fastcall__ buffer_platform(unsigned int start_address, char length);
void __fastcall__ buffer_row(unsigned int nametable, char row);
void __fastcall__ clear_row(unsigned int nametable, char row);
