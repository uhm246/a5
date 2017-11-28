#ifndef GRID_H
#define GRID_H
#include <iostream>
#include <vector>
#include <cstddef>
#include "cell.h"
#include "state.h"
#include "info.h"
#include "block.h"
#include "level.h"

class TextDisplay;
template <typename InfoType, typename StateType> class Observer;
class InvalidMove{};

class Grid {
  std::vector<std::vector<Cell>> theGrid;
  TextDisplay *td = nullptr;
  Observer<Info, State> *ob = nullptr; 

 public:
  ~Grid();
  
  void setObserver(Observer<Info, State> *ob);
  void clearLine();
  void init(size_t n);
  void setBlock(Block b);
  void hint();
  int getScore();
  Level getLevel();
  Block getBlock(Level);
  bool isFull() const; 

  friend std::ostream &operator<<(std::ostream &out, const Grid &g);
};

#endif
