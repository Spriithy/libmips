#include <stdio.h>
#include "instruction.h"

int main() {
  instr_t i = 0x012a4020;
  printf("0x%02x[0x%02x] $%d, $%d, $%d\n", OP(i), FUNCT(i), RD(i), RS(i),
         RT(i));
}
