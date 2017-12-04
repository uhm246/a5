#ifndef CELL_H
#define CELL_H
#include <cstddef>
#include "state.h"
#include "subject.h"
#include "block.h"

class Cell : public Subject<State> {
  const size_t r, c;
  Status status;
  Type type;
  Block* block;

 public:
  Cell(size_t r, size_t c);
  void setStatus(Status s);
  void setType(Type t);
  Block* getBlock();
  void setBlock(Block* b);

};
#endif
