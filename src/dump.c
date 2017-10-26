/*
 * disas.c
 *
 *  Created on: Oct 26, 2017
 *      Author: theophile
 */

#include <libmips/32/decode.h>
#include <libmips/32/dump.h>
#include <libmips/32/instructions.h>
#include <libmips/32/registers.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME instruction_name(i)
#define RT register_name(DECODE_RT(i))
#define RS register_name(DECODE_RS(i))
#define RD register_name(DECODE_RD(i))
#define FUNCT DECODE_FUNCT(i)
#define SHAMT DECODE_SHT(i)
#define S_IMM (int16_t) DECODE_IMM_I(i)
#define U_IMM (uint16_t) DECODE_IMM_I(i)

char* dump_raw_instr(uint32_t i)
{
    char* str = malloc(32);
    int op = DECODE_OP(i);
    switch (op) {
    case 0:
        switch (FUNCT) {
        case SLL:
        case SRA:
            sprintf(str, "%-7s%s, %s, %u", NAME, RD, RT, SHAMT);
            break;
        case SLLV:
        case SRLV:
        case SRAV:
            sprintf(str, "%-7s%s, %s, %s", NAME, RD, RT, RS);
            break;
        case MOVZ:
        case MOVN:
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
            sprintf(str, "%-7s%s, %s, %s", NAME, RD, RS, RT);
            break;
        case JALR:
            sprintf(str, "%-7s%s, %s", NAME, RD, RS);
            break;
        case MULT:
        case MULTU:
        case DIV:
        case DIVU:
        case TGE:
        case TGEU:
        case TLT:
        case TLTU:
        case TEQ:
        case TNE:
            sprintf(str, "%-7s%s, %s", NAME, RS, RT);
            break;
        case JR:
        case MTHI:
        case MTLO:
            sprintf(str, "%-7s%s", NAME, RS);
            break;
        case MFHI:
        case MFLO:
            sprintf(str, "%-7s%s", NAME, RD);
            break;
        case SYSCALL:
        case BREAK:
        case SYNC:
            sprintf(str, "%-7s", NAME);
            break;
        default:
            sprintf(str, "<0x%X>", i);
        }
        break;
    case 1:
        switch (DECODE_RT(i)) {
        case BLTZ:
        case BGEZ:
        case BLTZL:
        case BGEZL:
        case TGEI:
        case TLTI:
        case TEQI:
        case TNEI:
        case BLTZAL:
        case BGEZAL:
        case BLTZALL:
        case BGEZALL:
            sprintf(str, "%-7s%s, %d", NAME, RS, S_IMM << 2);
            break;
        case TGEIU:
        case TLTIU:
            sprintf(str, "%-7s%s, %u", NAME, RS, U_IMM);
            break;
        }
        break;
    case J:
    case JAL:
        sprintf(str, "%-7s%d", NAME, (int32_t)DECODE_IMM_J(i) << 2);
        break;
    case BEQ:
    case BNE:
        sprintf(str, "%-7s%s, %s, %d", NAME, RT, RS, S_IMM << 2);
        break;
    case BLEZ:
    case BGTZ:
        sprintf(str, "%-7s%s, %d", NAME, RT, S_IMM << 2);
        break;
    case ADDI:
    case SLTI:
        sprintf(str, "%-7s%s, %s, %d", NAME, RT, RS, S_IMM);
        break;
    case BEQL:
    case BNEL:
    case BLEZL:
    case BGTZL:
        sprintf(str, "%-7s%s, %s, %d", NAME, RT, RS, S_IMM << 2);
        break;
    case ADDIU:
    case SLTIU:
        sprintf(str, "%-7s%s, %s, %u", NAME, RT, RS, U_IMM);
        break;
    case ANDI:
    case ORI:
    case XORI:
        sprintf(str, "%-7s%s, %s, 0x%x", NAME, RT, RS, U_IMM);
        break;
    case LUI:
        sprintf(str, "%-7s%s, 0x%x", NAME, RT, U_IMM);
        break;
    case LB:
    case LH:
    case LWL:
    case LW:
    case LBU:
    case LHU:
    case LWR:
    case SB:
    case SH:
    case SWL:
    case SW:
    case SWR:
    case LL:
    case SC:
        sprintf(str, "%-7s%s, %d(%s)", NAME, RT, S_IMM, RS);
        break;
    case CACHE:
        sprintf(str, "%-7s0x%x, %d(%s)", NAME, DECODE_RT(i), S_IMM, RS);
        break;
    case PREF:
        sprintf(str, "%-7s0x%x, %d(%s)", NAME, DECODE_RT(i), S_IMM, RS);
        break;
    default:
        sprintf(str, "<0x%X>", i);
    }
    return str;
}

char* dump_raw(uint32_t* is, size_t n)
{
    size_t ofs = 0;
    char* tmp;
    char* str = malloc(n * 33);
    for (size_t i = 0; i < n; i++) {
        tmp = dump_raw_instr(is[i]);
        strcpy(str + ofs, tmp);
        ofs += strlen(tmp);
        str[ofs++] = '\n';
    }
    str[ofs - 1] = '\0';
    return str;
}
