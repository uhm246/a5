#ifndef CELL_H
#define CELL_H
#include <cstddef>
#include "state.h"
#include "info.h"
#include "subject.h"

class Cell : public Subject<Info, State> {
  const size_t r, c;
  Status status;
  Type type;

 public:
  Cell(size_t r, size_t c);
  Info getInfo() const override;
  void setStatus(Status s);
  void setType(Type t);

};
#endif
