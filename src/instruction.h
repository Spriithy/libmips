#ifndef MIPS_INSTRUCTION_H
#define MIPS_INSTRUCTION_H

#include <stdint.h>

typedef int32_t instr_t;

#define OP(i) (i >> 26)
#define RS(i) (i << 6 >> 27)
#define RT(i) (i << 11 >> 27)
#define RD(i) (i << 16 >> 27)
#define FUNCT(i) (i & 0x3f)
#define SHAMT(i) (i & 0x7c0)
#define I_IMM(i) (i & 0x0000ffff)
#define J_IMM(i) (i & 0x03ffffff)

#define __R 0x00

#define SLL 0x00
#define SRL 0x02
#define SRA 0x03
#define SLLV 0x04
#define SRLV 0x06
#define SRAV 0x07
#define JR 0x08
#define JALR 0x09
#define SYSCALL 0x0c
#define MFHI 0x10
#define MTHI 0x11
#define MFLO 0x12
#define MTLO 0x13
#define MULT 0x18
#define MULTU 0x19
#define DIV 0x1a
#define DIVU 0x1b
#define ADD 0x20
#define ADDU 0x21
#define SUB 0x22
#define SUBU 0x23
#define AND 0x24
#define OR 0x25
#define XOR 0x26
#define NOT 0x27
#define SLT 0x2a
#define SLTU 0x2b

#define J 0x02
#define JAL 0x03

#define BEQ 0x04
#define BNE 0x05
#define BLEZ 0x06
#define BGTZ 0x07
#define ADDI 0x08
#define ADDIU 0x09
#define SLTI 0x0a
#define SLTIU 0x0b
#define ANDI 0x0c
#define ORI 0x0d
#define XORI 0x0e
#define LUI 0x0f
#define LB 0x20
#define LH 0x21
#define LW 0x22
#define LBU 0x24
#define LHU 0x25
#define SB 0x28
#define SH 0x29
#define SW 0x2b

#endif  // MIPS_INSTRUCTION_H
