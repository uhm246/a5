#ifndef CELL_H
#define CELL_H
#include <cstddef>
#include "state.h"
#include "subject.h"

class Block;

class Cell : public Subject<State> {
  size_t r, c;
  Status status;
  Type type;
  Block* block;

 public:
  Cell(size_t r, size_t c);
  size_t getRow();
  size_t getCol();
  void setStatus(Status s);
  void setType(Type t);
  Block* getBlock();
  void setBlock(Block* b);

};
#endif
