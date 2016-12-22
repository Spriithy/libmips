#ifndef MIPS_MEMORY_H
#define MIPS_MEMORY_H

#include <stdint.h>

typedef uint8_t ubyte_t;
typedef int8_t byte_t;
typedef uint32_t uword_t;
typedef int32_t word_t;

typedef uint32_t hilo[2];

#define READ_BYTE(at) (byte_t)(mem[at])
#define READ_UBYTE(at) (ubyte_t)(mem[at])
#define READ_HALF(at) (int16_t)((mem[at] << 8) | mem[at + 1])
#define READ_UHALF(at) (uint16_t)((mem[at] << 8) | mem[at + 1])
#define READ_WORD(at) (word_t)((HALF(at) << 16) | HALF(at + 2))
#define READ_UWORD(at) (uword_t)((HALF(at) << 16) | HALF(at + 2))

#define WRITE_BYTE(at, b) mem[at] = (byte_t)b;
#define WRITE_UBYTE(at, b) mem[at] = (ubyte_t)b;
#define WRITE_HALF(at, h) \
  WRITE_BYTE(at, h >> 8); \
  WRITE_BYTE(at + 1, h);
#define WRITE_UHALF(at, h) \
  WRITE_UBYTE(at, h >> 8); \
  WRITE_UBYTE(at + 1, h);
#define WRITE_WORD(at, w)  \
  WRITE_HALF(at, w >> 16); \
  WRITE_HALF(at + 2, w);
#define WRITE_UWORD(at, w)  \
  WRITE_UHALF(at, w >> 16); \
  WRITE_UHALF(at + 2, w);

#endif  // MIPS_MEMORY_H
