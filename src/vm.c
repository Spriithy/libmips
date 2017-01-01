#include "vm.h"
#include "instruction.h"
#include "memory.h"
#include "trace.h"

uint8_t op, rs, rt, rd, shamt, funct;
int16_t i_imm;
int32_t j_imm;

uint64_t r[32];
word_t *stack;

#define SAVE()

#define RESTORE()

#define DECODE()

#define DISPATCH() DECODE()

int execute(instr_t *code) { return 0; }
