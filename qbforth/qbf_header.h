#pragma once
#include <stdint.h>

/* 	DESCRIPTION OF QBF
 *
 * 		Outline of QBF Header
 * 		7         6 5         0
 * 		+----------+----------+
 * 		| QBF_TYPE | QBF_INFO |
 * 		+----------+----------+
 * 
 * 		QBI_INFO can be thought of as a union of QBF_(TYPE)_INFO flag structures
 *
 * 		Outline of QBF_DEF and QBF_WORD
 * 		5     0
 * 		+-----+
 * 		| TAG | 
 * 		+-----+
 *
 * 		Outline of QBF_BUILTIN
 * 		5     4 3    0
 * 		+------+-----+
 * 		| SIZE | TAG |
 * 		+------+-----+
 * 
 * 		Outline of QBF_NUM_INFO
 * 		5		  4     0
 * 		+--------+------+
 * 		| SIGNED | SIZE |
 * 		+--------+------+
 * 		The size of the number is 2^(3+SIZE), so smalled size is 8-bits (0x00)
 * 		Maximum size in this implementation is 64-bit (0b00011) but you could implement up to 280-bit if you so desire
 *
 * 
 */
/*	BINARY WORKSPACE (I never thought being able to do BIN->HEX in my head would be useful) */
/*	PRINT: 0b11010100 =>  12 4 => 0xD4*/
enum QBF_TYPE {
	QBF_TYPE_DEFINITION,
	QBF_TYPE_WORD,
	QBF_TYPE_NUM,
	QBF_TYPE_BUILTIN,
};

enum QBF_BUILTIN_TAG {
	QBF_ADD,
	QBF_SUB,
	QBF_MUL,
	QBF_DIV,
	QBF_PRINT,
	QBF_POP,
	QBF_DUP,
};
#define QBF_TYPE_RSHIFT 6
#define QBF_TYPE_MASK 0b11000000

#define QBF_NUM_SIGNED_RSHIFT 4
#define QBF_NUM_SIGNED_MASK 0b00100000

#define QBF_NUM_SIZE_RSHIFT 0
#define QBF_NUM_SIZE_MASK 0b00011111

#define QBF_DEF_TAG_RSHIFT 0
#define QBF_DEF_TAG_MASK 0b00111111

#define QBF_WORD_TAG_RSHIFT 0
#define QBF_WORD_TAG_MASK 0b00111111

#define QBF_BUILTIN_TAG_RSHIFT 0
#define QBF_BUILTIN_TAG_MASK 0b00001111
#define QBF_BUILTIN_SIZE_RSHIFT 3
#define QBF_BUILTIN_SIZE_MASK 0b00110000

#define QBF_GET(header, FLAG) \
	(header & QBF_##FLAG##_MASK) >> QBF_##FLAG##_RSHIFT

#define QBF_SIZE_CONVERT(n) \
	(1 << (3+n))

typedef uint8_t qbf_head_t;