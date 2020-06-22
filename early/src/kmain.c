#include <stdint.h>
#include <curses/curses.h>
#include <kernel/string.h>

void kmain() {
    mvprint(0, 0, "This SHOULD be above :fingers_crossed:");
    mvprint(1, 0,"test string");
}
