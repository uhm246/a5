#ifndef CELL_H
#define CELL_H
#include <cstddef>
#include "state.h"
#include "subject.h"

class Cell : public Subject<State> {
  const size_t r, c;
  Status status;
  Type type;

 public:
  Cell(size_t r, size_t c);
  void setStatus(Status s);
  void setType(Type t);

};
#endif
