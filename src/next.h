#ifndef NEXT_H
#define NEXT_H
#include <vector>
#include "block.h"
#include "cell.h"

class Next {
  std::vector<std::vector<Cell>> theGrid;
  //TextDisplay *td = nullptr;
  //GraphicsDisplay *gd = nullptr;

public:
  const int width = 11;
  const int height = 2;
  void init();
  void setNext(Block b);
  //void setGraphicsDisplay();
  //void setTextDisplay();

};

#endif