#include "chunk.h"
#include "common.h"
#include "debug.h"

int main(int argc, char *argv[]) {
  Chunk chunk;

  init_chunk(&chunk);

  int constant = add_constant(&chunk, 2.1);

  write_chunk(&chunk, OP_CONSTANT, 420);
  write_chunk(&chunk, constant, 420);

  write_chunk(&chunk, OP_RETURN, 420);

  disassemble_chunk(&chunk, "test chunk");

  free_chunk(&chunk);

  return 0;
}
