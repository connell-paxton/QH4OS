#include <kernel/string.h>

uint32_t strlen(const char* s) {
    uint32_t i;
    for(i = 0; *s != 0; i++)
        s++;
    return i;
}