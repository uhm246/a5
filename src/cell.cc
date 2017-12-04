#include "cell.h"

Cell::Cell(size_t r, size_t c): 
r(r), c(c), status(Status::Empty), type(Type::None), block(nullptr){
  State st { r, c, status, type };
  setState(st);
}

size_t Cell::getRow(){
  return r;
}

size_t Cell::getCol(){
  return c;
}

void Cell::setStatus(Status s){
  status = s;
  State st { r, c, status, type };
  setState(st);
}

void Cell::setType(Type t){
  type = t;
  State st { r, c, status, type };
  setState(st);
}

void Cell::setBlock(Block* b){
  block = b;
}

Block* Cell::getBlock(){
  return block;
}


