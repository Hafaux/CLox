#include "chunk.h"
#include "common.h"
#include "debug.h"
#include "vm.h"

int main(int argc, char *argv[]) {
  init_vm();

  Chunk chunk;

  init_chunk(&chunk);

  int constant = add_constant(&chunk, 2.2);

  write_chunk(&chunk, OP_CONSTANT, 420);
  write_chunk(&chunk, constant, 420);

  constant = add_constant(&chunk, 3.4);

  write_chunk(&chunk, OP_CONSTANT, 420);
  write_chunk(&chunk, constant, 420);

  write_chunk(&chunk, OP_ADD, 420);

  constant = add_constant(&chunk, 5.6);

  write_chunk(&chunk, OP_CONSTANT, 420);
  write_chunk(&chunk, constant, 420);

  write_chunk(&chunk, OP_DIVIDE, 420);
  write_chunk(&chunk, OP_NEGATE, 420);

  write_chunk(&chunk, OP_RETURN, 420);

  // disassemble_chunk(&chunk, "test chunk");

  interpret(&chunk);

  free_vm();
  free_chunk(&chunk);

  return 0;
}
