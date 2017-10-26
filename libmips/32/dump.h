/*
 * disas.h
 *
 *  Created on: Oct 26, 2017
 *      Author: theophile
 */

#ifndef LIBMIPS_DUMP_H_
#define LIBMIPS_DUMP_H_

#include <stddef.h>
#include <stdint.h>

char *dump_raw_instr(uint32_t);

char *dump_raw(uint32_t *, size_t);

#endif /* LIBMIPS_DUMP_H_ */
