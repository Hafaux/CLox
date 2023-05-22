#include "vm.h"

#include <stdio.h>

#include "chunk.h"
#include "common.h"
#include "value.h"

VM vm;

void init_vm() {}

void free_vm() {}

static InterpreterResult run() {
#define READ_BYTE() (*vm.ip++)
#define READ_CONSTANT() (vm.chunk->constants.values[READ_BYTE()])

  for (;;) {
    uint8_t instruction;

    switch (instruction = READ_BYTE()) {
      case OP_CONSTANT: {
        Value constant = READ_CONSTANT();

        print_value(constant);
        printf("\n");

        break;
      }
      case OP_RETURN: {
        return INTERPRET_OK;
      }
    }
  }

#undef READ_BYTE
#undef READ_CONSTANT
}

InterpreterResult interpret(Chunk* chunk) {
  vm.chunk = chunk;
  vm.ip = vm.chunk->code;

  return run();
}
