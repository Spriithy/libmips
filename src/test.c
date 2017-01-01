#include <stdio.h>
#include "builtins/gen.h"
#include "instruction.h"
#include "trace.h"

int main() {
  instr_t i = GEN_SYSCALL();
  trace(i);
}
