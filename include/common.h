#ifndef COMMON_H
#define COMMON_H

/* Shared basic types for the THUG decomp. Game classes live in include/game/. */

typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
typedef signed long s64;          /* EE gcc: long is 64-bit (mips3, -mabi=eabi) */
typedef unsigned long u64;
typedef float f32;
typedef double f64;

#ifndef NULL
#define NULL 0
#endif

#endif
