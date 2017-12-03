#include "cell.h"

Cell::Cell(size_t r, size_t c): 
r(r), c(c), status(Status::Empty), type(Type::None){
  State state { r, c, status, type };
  setState(state);
}

void Cell::setStatus(Status s){
  status = s;
  State state { r, c, status, type };
  setState(state);
}

void Cell::setType(Type t){
  type = t;
  State state { r, c, status, type };
  setState(state);
}
