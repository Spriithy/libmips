/*
 * decode.h
 *
 *  Created on: Oct 26, 2017
 *      Author: theophile
 */

#ifndef LIBMIPS_DECODE_H_
#define LIBMIPS_DECODE_H_

#define DECODE_OP(i) (i >> 26)

#define DECODE_RS(i) (i >> 21) & 0x1f
#define DECODE_RT(i) (i >> 16) & 0x1f
#define DECODE_RD(i) (i >> 11) & 0x1f

#define DECODE_SHT(i) (i >> 6) & 0x1f

#define DECODE_FUNCT(i) (i & 0x3f)

#define DECODE_IMM_I(i) (i & 0xffff)

#define DECODE_IMM_J(i) (i & 0x03ffffff) | ((i >> 25) & 0x1 ? 0xfc000000 : 0)

#define DECODE_R(i, op, rs, rt, sht, funct) \
    op = DECODE_OP(i);                      \
    rs = DECODE_RS(i);                      \
    rt = DECODE_RT(i);                      \
    rd = DECODE_RD(i);                      \
    sht = DECODE_SHT(i);                    \
    funct = DECODE_FUNCT(i)

#define DECODE_J(i, op, imm) \
    op = DECODE_OP(i);       \
    imm = DECODE_IMM_J(i)

#define DECODE_I(i, op, rs, rt, imm) \
    op = DECODE_OP(i);               \
    rs = DECODE_RS(i);               \
    rt = DECODE_RT(i);               \
    imm = DECODE_IMM_I(i)

#endif /* LIBMIPS_DECODE_H_ */
