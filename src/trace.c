#include "trace.h"
#include <stdio.h>

char RN[][5] = {"zero", "at", "v0", "v1", "a0", "a1", "a2", "a3",
                "t0",   "t1", "t2", "t3", "t4", "t5", "t6", "t7",
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
    PH,      PH,     PH,      PH,     "beq", "bne",  "blez", "bgtz", "addi",
    "addiu", "slti", "sltiu", "andi", "ori", "xori", "lui",  PH,     PH,
    PH,      PH,     PH,      PH,     PH,    PH,     PH,     PH,     PH,
    PH,      PH,     PH,      PH,     PH,    "lb",   "lh",   "lw",   PH,
    "lbu",   "lhu",  PH,      PH,     "sb",  "sh",   PH,     "sw",
};

FILE *f;

void trace(instr_t i) {
  f = stdout;

  int op = OP(i);
  int funct = FUNCT(i);

  char *name = I_INAME[op];
  if (op == __R) name = R_INAME[funct];
  fprintf(f, "%-7s ", name);
  switch (op) {
    case __R: {
      switch (funct) {
        case SYSCALL:
          return;
        case MFHI:
        case MFLO:
          fprintf(f, "$%s\n", RN[RD(i)]);
          return;
        case JR:
        case MTHI:
        case MTLO:
          fprintf(f, "$%s\n", RN[RS(i)]);
          return;
        case JALR:
          fprintf(f, "$%s, $%s\n", RN[RD(i)], RN[RS(i)]);
          return;
        case MULT:
        case MULTU:
        case DIV:
        case DIVU:
          fprintf(f, "$%s, $%s\n", RN[RS(i)], RN[RT(i)]);
          return;
        case SLL:
        case SRL:
        case SRA:
          fprintf(f, "$%s, $%s, %u\n", RN[RD(i)], RN[RT(i)], SHAMT(i));
          return;
        case SLLV:
        case SRLV:
        case SRAV:
          fprintf(f, "$%s, $%s, $%s\n", RN[RD(i)], RN[RT(i)], RN[RS(i)]);
          return;
        case ADD:
        case ADDU:
        case SUB:
        case SUBU:
        case AND:
        case OR:
        case XOR:
        case NOR:
        case SLT:
        case SLTU:
          fprintf(f, "$%s, $%s, $%s\n", RN[RD(i)], RN[RS(i)], RN[RT(i)]);
          return;
      }
    }
    case J:
    case JAL:
      fprintf(f, "%d\n", J_IMM(i));
      return;
    case LUI:
      fprintf(f, "$%s, %d\n", RN[RT(i)], (int16_t)I_IMM(i));
      return;
    case BLEZ:
    case BGTZ:
      fprintf(f, "$%s, %d\n", RN[RS(i)], (int16_t)I_IMM(i));
      return;
    case BEQ:
    case BNE:
      fprintf(f, "$%s, $%s, %d\n", RN[RS(i)], RN[RT(i)], (int16_t)I_IMM(i));
      return;
    case ADDI:
    case ADDIU:
    case SLTI:
    case SLTIU:
    case ANDI:
    case ORI:
    case XORI:
      fprintf(f, "$%s, $%s, %d\n", RN[RT(i)], RN[RS(i)], (int16_t)I_IMM(i));
      return;
    default:
      fprintf(f, "$%s, %d($%s)\n", RN[RT(i)], (int16_t)I_IMM(i), RN[RS(i)]);
  }
}
