#ifndef CELL_H
#define CELL_H
#include <cstddef>
#include "state.h"
#include "subject.h"
#include "observer.h"
#include "info.h"

class Cell : public Subject<Info, State>, public Observer<Info, State> {
  const size_t r, c;
  bool exist;

 public:
  Cell(size_t r, size_t c);
  bool isFilled();
  void unfill();
};
#endif
