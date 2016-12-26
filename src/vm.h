#ifndef MIPS_VM_H
#define MIPS_VM_H

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "instruction.h"

int execute(instr_t *code);

#endif  // MIPS_VM_H
