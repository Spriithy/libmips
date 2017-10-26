/*
 * encode.h
 *
 *  Created on: Oct 26, 2017
 *      Author: theophile
 */

#ifndef LIBMIPS_ENCODE_H_
#define LIBMIPS_ENCODE_H_

#define ENCODE_R(op, rs, rt, rd, sht, funct) \
  (funct) | (sht << 6) | (rd << 11) | (rt << 16) | (rs << 21) | (op << 26)

#define ENCODE_J(op, addr) (addr & 0x03ffffff) | (op << 26)

#define ENCODE_I(op, rs, rt, imm) \
  (imm & 0xffff) | (rt << 16) | (rs << 21) | (op << 26)

#endif /* LIBMIPS_ENCODE_H_ */
