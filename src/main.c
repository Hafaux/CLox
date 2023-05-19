#include "common.h"
#include "chunk.h"
#include "debug.h"

int main(int argc, char *argv[])
{
  Chunk chonk;

  init_chunk(&chonk);
  write_chunk(&chonk, OP_RETURN);

  disassemble_chunk(&chonk, "test chunk");
  
  free_chunk(&chonk);

  return 0;
}
