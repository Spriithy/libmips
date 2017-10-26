/*
 * instructions.h
 *
 *  Created on: Oct 26, 2017
 *      Author: theophile
 */

#ifndef LIBMIPS_INSTRUCTIONS_H_
#define LIBMIPS_INSTRUCTIONS_H_

#include <stdint.h>

#define SKIP(s, n) s + n + 1

char* instruction_name(uint32_t);

enum {
    __FUNCT_0, // see table funct_0
    __RT_0, // see table rt_0
    J,
    JAL,
    BEQ,
    BNE,
    BLEZ,
    BGTZ,
    ADDI,
    ADDIU,
    SLTI,
    SLTIU,
    ANDI,
    ORI,
    XORI,
    LUI,
    __RS_0_0, // see table rs_0 [Z = 0]
    __RS_0_1, // see table rs_0 [Z = 1]
    __RS_0_2, // see table rs_0 [Z = 2]
    BEQL = SKIP(LUI, 4),
    BNEL,
    BLEZL,
    BGTZL,
    LB = SKIP(BGTZL, 8),
    LH,
    LWL,
    LW,
    LBU,
    LHU,
    LWR,
    SB = SKIP(LWR, 1),
    SH,
    SWL,
    SW,
    SWR = SKIP(SW, 2),
    CACHE,
    LL,
    LWC1,
    LWC2,
    PREF,
    LDC1 = SKIP(PREF, 1),
    LDC2,
    SC = SKIP(LDC2, 1),
    SWC1,
    SWC2,
    SDC1 = SKIP(SWC2, 2),
    SDC2
};

enum funct_0 {
    SLL,
    SRL = SKIP(SLL, 1),
    SRA,
    SLLV,
    SRLV = SKIP(SLLV, 1),
    SRAV,
    JR,
    JALR,
    MOVZ,
    MOVN,
    SYSCALL,
    BREAK,
    SYNC = SKIP(BREAK, 1),
    MFHI,
    MTHI,
    MFLO,
    MTLO,
    MULT = SKIP(MTLO, 4),
    MULTU,
    DIV,
    DIVU,
    ADD = SKIP(DIVU, 4),
    ADDU,
    SUB,
    SUBU,
    AND,
    OR,
    XOR,
    NOR,
    SLT = SKIP(NOR, 2),
    SLTU,
    TGE = SKIP(SLTU, 4),
    TGEU,
    TLT,
    TLTU,
    TEQ,
    TNE = SKIP(TEQ, 1),
};

enum rt_0 {
    BLTZ,
    BGEZ,
    BLTZL,
    BGEZL,
    TGEI = SKIP(BGEZL, 4),
    TGEIU,
    TLTI,
    TLTIU,
    TEQI,
    TNEI = SKIP(TEQI, 1),
    BLTZAL = SKIP(TNEI, 1),
    BGEZAL,
    BLTZALL,
    BGEZALL,
};

#endif /* LIBMIPS_INSTRUCTIONS_H_ */
