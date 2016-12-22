#ifndef MIPS_TRACE_H
#define MIPS_TRACE_H

#include "instruction.h"

char RN[][5] = {"zero", "at", "v0", "v1", "a0", "a1", "a2", "a3",
                "a0",   "a1", "a2", "a3", "a4", "a5", "a6", "a7",
                "s0",   "s1", "s2", "s3", "s4", "s5", "s6", "s7",
                "t8",   "t9", "k0", "k1", "gp", "sp", "fp", "ra"};

#define PH "<?>"

char R_INAME[][8] = {
    "sll",  PH,     "srl", "sra",     "sllv", PH,    "srlv", "srav",  "jr",
    "jalr", PH,     PH,    "syscall", PH,     PH,    PH,     "mfhi",  "mthi",
    "mflo", "mtlo", PH,    PH,        PH,     PH,    "mult", "multu", "div",
    "divu", PH,     PH,    PH,        PH,     "add", "addu", "sub",   "subu",
    "and",  "or",   "xor", "nor",     PH,     PH,    "slt",  "sltu",
};

char I_INAME[][8] = {
    // todo
};

void trace(instr_t i);

#endif  // MIPS_TRACE_H
