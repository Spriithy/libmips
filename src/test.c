#include <stdio.h>
#include "instruction.h"
#include "trace.h"

int main() {
  instr_t i = 0x012a4020;
  trace(i);
}
