#ifndef VGA_H_
#define VGA_H_
#include <stdint.h>
#define vga_write(x, y, word) \
    vga_mem[(y*80)+x] =  word

extern unsigned short* vga_mem;

void vga_update_cursor(int y, int x);

enum vga_color {
    TEST
};
#endif /* VGA_H_ */