#include <stdio.h>
#include "builtins/gen.h"
#include "instruction.h"
#include "trace.h"

int main() {
  instr_t i = GEN_ADDI(19, 14, -9);
  trace(i);
}
