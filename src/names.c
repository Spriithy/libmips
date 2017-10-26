/*
 * mips32.c
 *
 *  Created on: Oct 26, 2017
 *      Author: theophile
 */

#include <libmips/32/decode.h>

char *rnames[] = {
    "$zero", "$at", "$v0", "$v1", "$a0", "$a1", "$a2", "$a3",
    "$t0",   "$t1", "$t2", "$t3", "$t4", "$t5", "$t6", "$t7",
    "$s0",   "$s1", "$s2", "$s3", "$s4", "$s5", "$s6", "$s7",
    "$t8",   "$t9", "$k0", "$k1", "$gp", "$sp", "$fp", "$ra",
};

char *register_name(const int r) { return rnames[r]; }

#define _ "?"

char *inames[] = {
    _,       _,      "j",     "jal",  "beq",   "bne",   "blez", "bgtz", "addi",
    "addiu", "slti", "sltiu", "andi", "ori",   "xori",  "lui",  _,      _,
    _,       _,      "beql",  "bnel", "blezl", "bgtzl", _,      _,      _,
    _,       _,      _,       _,      _,       "lb",    "lh",   "lwl",  "lw",
    "lbu",   "lhu",  "lwr",   _,      "sb",    "sh",    "swl",  "sw",   _,
    _,       "swr",  "cache", "ll",   "lwc1",  "lwc2",  "pref", _,      "ldc1",
    "ldc2",  _,      "sc",    "swc1", "swc2",  _,       _,      "sdc1", "sdc2",
};

char *funct0[] = {
    "sll",  _,       "srl",  "sra",  "sllv",    _,       "srlv", "srav",
    "jr",   "jalr",  "movz", "movn", "syscall", "break", _,      "sync",
    "mfhi", "mthi",  "mflo", "mtlo", _,         _,       _,      _,
    "mult", "multu", "div",  "divu", _,         _,       _,      _,
    "add",  "addu",  "sub",  "subu", "and",     "or",    "xor",  "nor",
    _,      _,       "slt",  "sltu", _,         _,       _,      _,
    "tge",  "tgeu",  "tlt",  "tltu", "teq",     _,       "tne",
};

char *rt0[] = {
    "bltz", "bgez", "bltzl",  "bgezl",  _,         _,         _,
    _,      "tgei", "tgeiu",  "tlti",   "tltiu",   "tegi",    _,
    "tnei", _,      "bltzal", "bgezal", "bltzall", "bgezall",
};

char *instruction_name(unsigned i) {
  int op = DECODE_OP(i);
  if (op == 0) return funct0[DECODE_FUNCT(i)];
  if (op == 1) return rt0[DECODE_RT(i)];
  if (op > 1) return inames[op];
  return "?";
}

