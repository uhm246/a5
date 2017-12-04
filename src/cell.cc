#include "cell.h"
#include "observer.h"

Cell::Cell(size_t r, size_t c): 
r(r), c(c), status(Status::Empty), type(Type::None), block(nullptr){
  State st { r, c, status, type, blocktype };
  setState(st);
}

size_t Cell::getRow(){
  return r;
}

size_t Cell::getCol(){
  return c;
}

void Cell::setNext(){
  blocktype = BlockType::Next;
}

Type Cell::getType() {
	return type;
}

void Cell::setStatus(Status s){
  status = s;
  State st { r, c, status, type, blocktype };
  setState(st);
}

void Cell::setType(Type t){
  type = t;
  State st { r, c, status, type, blocktype };
  setState(st);
  notifyObservers();
}

void Cell::setBlock(Block* b){
  block = b;
}

Block* Cell::getBlock(){
  return block;
}


