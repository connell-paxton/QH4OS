#include <stdio.h>
#include <stdlib.h>
#include "qbf.h"

int main() {
	uint8_t tag, size;
	uint64_t value, x, y, r;
	uint8_t* stack = malloc(256);
	for(;;) {
		int a = getchar();
		switch(a) {
			case EOF:
				goto exit;
			break;
			default:
				switch (QBF_GET(a, TYPE))
				{
				case QBF_TYPE_NUM:
					for(size_t i = 0; i < QBF_SIZE_CONVERT(QBF_GET(a, NUM_SIZE))/8; i++) {
						*stack = (uint8_t)getchar();
						printf("%x ", *stack);
						stack++;
					}
					//stack;
					putchar(0x0A);
				break;
				
				case QBF_TYPE_BUILTIN:
					tag = QBF_GET(a, BUILTIN_TAG);
					switch(tag) {
					case QBF_ADD:;
						size = QBF_SIZE_CONVERT(QBF_GET(a, BUILTIN_SIZE))/8;
						stack -= (size*2);
						x = *stack;
						printf("%x", *stack);
						stack++;
						for(size_t i = 1; i < size; i++) {
							x <<= 8;
							x |= *stack;
							printf(" %x", *stack);
							stack++;
						}
						putchar(0x0A);
						y = *stack;
						printf("%x", *stack);
						stack++;
						for(size_t i = 1; i < size; i++) {
							y <<= 8;
							y |= *stack;
							printf(" %x", *stack);
							stack++;
						}
						putchar(0x0A);
						r = x+y;
						printf("%llx\n", r);
						stack -= size * 2;
						for(uint8_t i = 0; i < size; i++) {
							*stack = (uint8_t)((r >> 8*i) & 0x000000ff);
							stack--;
						}
						stack++;
						for(uint8_t i = 0; i < size; i++) {
							printf("%x ", *stack);
							stack++;
						}
						putchar(0x0A);
					break;
					case QBF_SUB:;
						x, y;
						size = QBF_SIZE_CONVERT(QBF_GET(a, BUILTIN_SIZE))/8;
						stack -= (size*2);
						x = *stack;
						printf("%x", *stack);
						stack++;
						for(size_t i = 1; i < size; i++) {
							x <<= 8;
							x |= *stack;
							printf(" %x", *stack);
							stack++;
						}
						putchar(0x0A);
						y = *stack;
						printf("%x", *stack);
						stack++;
						for(size_t i = 1; i < size; i++) {
							y <<= 8;
							y |= *stack;
							printf(" %x", *stack);
							stack++;
						}
						putchar(0x0A);
						r = x-y;
						printf("%llx\n", r);
						stack -= size * 2;
						for(uint8_t i = 0; i < size; i++) {
							*stack = (uint8_t)((r >> 8*i) & 0x000000ff);
							stack--;
						}
						stack++;
						for(uint8_t i = 0; i < size; i++) {
							printf("%x ", *stack);
							stack++;
						}
						putchar(0x0A);
					break;
					case QBF_MUL:;
						x, y;
						size = QBF_SIZE_CONVERT(QBF_GET(a, BUILTIN_SIZE))/8;
						stack -= (size*2);
						x = *stack;
						printf("%x", *stack);
						stack++;
						for(size_t i = 1; i < size; i++) {
							x <<= 8;
							x |= *stack;
							printf(" %x", *stack);
							stack++;
						}
						putchar(0x0A);
						y = *stack;
						printf("%x", *stack);
						stack++;
						for(size_t i = 1; i < size; i++) {
							y <<= 8;
							y |= *stack;
							printf(" %x", *stack);
							stack++;
						}
						putchar(0x0A);
						r = x*y;
						printf("%llx\n", r);
						stack -= size * 2;
						for(uint8_t i = 0; i < size; i++) {
							*stack = (uint8_t)((r >> 8*i) & 0x000000ff);
							stack--;
						}
						stack++;
						for(uint8_t i = 0; i < size; i++) {
							printf("%x ", *stack);
							stack++;
						}
						putchar(0x0A);
					break;
					case QBF_DIV:;
						x, y;
						size = QBF_SIZE_CONVERT(QBF_GET(a, BUILTIN_SIZE))/8;
						stack -= (size*2);
						x = *stack;
						printf("%x", *stack);
						stack++;
						for(size_t i = 1; i < size; i++) {
							x <<= 8;
							x |= *stack;
							printf(" %x", *stack);
							stack++;
						}
						putchar(0x0A);
						y = *stack;
						printf("%x", *stack);
						stack++;
						for(size_t i = 1; i < size; i++) {
							y <<= 8;
							y |= *stack;
							printf(" %x", *stack);
							stack++;
						}
						putchar(0x0A);
						r = x/y;
						printf("%llx\n", r);
						stack -= size * 2;
						for(uint8_t i = 0; i < size; i++) {
							*stack = (uint8_t)((r >> 8*i) & 0x000000ff);
							stack--;
						}
						stack++;
						for(uint8_t i = 0; i < size; i++) {
							printf("%x ", *stack);
							stack++;
						}
						putchar(0x0A);
					break;
					case QBF_PRINT:
						size = QBF_GET(a, BUILTIN_SIZE)/8;
						stack - size;
						printf("%x", *stack);
						stack++;
						for(uint8_t i = 0; i < size; i++) {
							printf(" %x", *stack);
							stack++;
						}
						putchar(0x0A);
					break;
					case QBF_POP:
						size = QBF_GET(a, BUILTIN_SIZE)/8;
						for(uint8_t i = 0; i < size; i++) {
							*stack = 0;
							stack--;
						}
					break;
					case QBF_DUP:
						size = QBF_GET(a, BUILTIN_SIZE)/8;
						stack -= size;
						for(uint8_t i = 0; i < size; i++) {
							*(stack+size) = *stack;
							stack++;
						}
						stack += size;
					break;
					}
				break;
				default:
				break;
				}
			break;
		}
	}
	exit:
	putchar(10);
	return 0;
}