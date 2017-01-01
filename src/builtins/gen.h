#ifndef MIPS_GEN_H
#define MIPS_GEN_H

#include "../trace.h"

#define GEN_SLL(rd, rt, shamt) \
  (SLL | (rd << 11) | (rt << 16) | ((shamt & 0xff) << 6))

#define GEN_SRL(rd, rt, shamt) \
  (SRL | (rd << 11) | (rt << 16) | ((shamt & 0xff) << 6))

#define GEN_SRA(rd, rt, shamt) \
  (SRA | (rd << 11) | (rt << 16) | ((shamt & 0xff) << 6))

#define GEN_SLLV(rd, rt, rs) (SLLV | (rt << 16) | (rd << 11) | (rs << 21))

#define GEN_SRLV(rd, rt, rs) (SRLV | (rt << 16) | (rd << 11) | (rs << 21))

#define GEN_SRAV(rd, rt, rs) (SRAV | (rt << 16) | (rd << 11) | (rs << 21))

#define GEN_JR(rs) (JR | (rs << 21))

#define GEN_JALR(rd, rs) (JALR | (rt << 11) | (rs << 21))

#define GEN_SYSCALL() (SYSCALL)

#define GEN_MFHI(rd) (MFHI | (rt << 11))

#define GEN_MTHI(rs) (MTHI | (rs << 21))

#define GEN_MFLO(rd) (MFLO | (rt << 11))

#define GEN_MTLO(rs) (MTLO | (rs << 21))

#define GEN_MULT(rs, rt) (MULT | (rt << 16) | (rs << 21))

#define GEN_MULTU(rs, rt) (MULTU | (rt << 16) | (rs << 21))

#define GEN_DIV(rs, rt) (DIV | (rt << 16) | (rs << 21))

#define GEN_DIVU(rs, rt) (DIVU | (rt << 16) | (rs << 21))

#define GEN_ADD(rd, rs, rt) (ADD | (rt << 16) | (rt << 11) | (rs << 21))

#define GEN_ADDU(rd, rs, rt) (ADDU | (rt << 16) | (rt << 11) | (rs << 21))

#define GEN_SUB(rd, rs, rt) (SUB | (rt << 16) | (rt << 11) | (rs << 21))

#define GEN_AND(rd, rs, rt) (AND | (rt << 16) | (rt << 11) | (rs << 21))

#define GEN_OR(rd, rs, rt) (OR | (rt << 16) | (rt << 11) | (rs << 21))

#define GEN_XOR(rd, rs, rt) (XOR | (rt << 16) | (rt << 11) | (rs << 21))

#define GEN_NOR(rd, rs, rt) (NOR | (rt << 16) | (rt << 11) | (rs << 21))

#define GEN_SLT(rd, rs, rt) (SLT | (rt << 16) | (rt << 11) | (rs << 21))

#define GEN_SLTU(rd, rs, rt) (SLTU | (rt << 16) | (rt << 11) | (rs << 21))

#define GEN_J(ofs) ((J << 26) | (J_IMM(ofs) & 0x03ffffff))

#define GEN_JAL(ofs) ((JAL << 26) | (J_IMM(ofs) & 0x03ffffff))

#define GEN_BEQ(rs, rt, ofs) \
  ((BEQ << 26) | (rt << 16) | (rs << 21) | I_IMM(ofs))

#define GEN_BNE(rs, rt, ofs) \
  ((BNE << 26) | (rt << 16) | (rs << 21) | I_IMM(ofs))

#define GEN_BLEZ(rs, ofs) ((BLEZ << 26) | (rs << 21) | I_IMM(ofs))

#define GEN_BGTZ(rs, ofs) ((BGTZ << 26) | (rs << 21) | I_IMM(ofs))

#define GEN_ADDI(rt, rs, imm) \
  ((ADDI << 26) | (rt << 16) | (rs << 21) | I_IMM(imm))

#define GEN_ADDIU(rt, rs, imm) \
  ((ADDIU << 26) | (rt << 16) | (rs << 21) | I_IMM(imm))

#define GEN_SLTI(rt, rs, imm) \
  ((SLTI << 26) | (rt << 16) | (rs << 21) | I_IMM(imm))

#define GEN_SLTIU(rt, rs, imm) \
  ((SLTIU << 26) | (rt << 16) | (rs << 21) | I_IMM(imm))

#define GEN_ANDI(rt, rs, imm) \
  ((ANDI << 26) | (rt << 16) | (rs << 21) | I_IMM(imm))

#define GEN_ORI(rt, rs, imm) \
  ((ORI << 26) | (rt << 16) | (rs << 21) | I_IMM(imm))

#define GEN_XORI(rt, rs, imm) \
  ((XORI << 26) | (rt << 16) | (rs << 21) | I_IMM(imm))

#define GEN_LUI(rs, imm) ((LUI << 26) | (rt << 16) | I_IMM(imm))

#define GEN_REGULAR(op, rt, imm, rs) \
  ((op << 26) | (rt << 16) | (rs << 21) | I_IMM(imm))

#endif  // MIPS_GEN_H
