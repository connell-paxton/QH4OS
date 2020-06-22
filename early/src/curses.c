#include <curses/curses.h>
#include <kernel/vga.h>
#include <kernel/string.h>

int cur_x = 0;
int cur_y = 0;
unsigned short color = 0x0F00;

void mvprint(int y, int x, const char* s) {
    uint32_t len = strlen(s);
    for(uint32_t i = 0; i < len; i++) {
        //vga_mem[i+(y*80)+x] = color | s[i];
        vga_write(x, y, color | s[i]);
    }
    vga_update_cursor(x+len, y);
}

void mvputchar(int y, int x, const char c) {
    vga_mem[x+(y*80)] = color | c;
    vga_update_cursor(x+1, y);
}