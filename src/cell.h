#ifndef CELL_H
#define CELL_H
#include <cstddef>
#include "state.h"
#include "subject.h"

class Block;

class Cell : public Subject<State> {
  size_t r, c;
  Fill status;
  Type type;
  Block* block;
  BlockType blocktype = BlockType::Current;

 public:
  Cell(size_t r, size_t c);
  size_t getRow();
  size_t getCol();
  void setNext();
  Type getType();
  void setStatus(Fill s);
  void setType(Type t);
  Block* getBlock();
  void setBlock(Block* b);

};
#endif
