#ifndef clox_value_h
#define clox_value_h

#include "common.h"

typedef double Value;

typedef struct {
  int count;
  int capacity;
  Value* values;
} value_array;

void init_value_array(value_array* array);
void write_value_array(value_array* array, Value value);
void free_value_array(value_array* array);
void print_value(Value value);

#endif  // !#ifndef clox_value_h
