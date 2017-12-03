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

class Grid {
  
  std::vector<std::vector<Cell>> theGrid;
  std::vector<Block&> blocks;
  TextDisplay *td = nullptr;
  Observer<Info, State> *ob = nullptr; 
  
  void clearLine(size_t r);
  void clearLines();

  int score = 0;
  int hiscore = 0;
  void resetScore();
  void increaseScore();
  void setHiScore();
  std::vector<int> checkBlocks();
 public:

  const width = 11;
  const height = 18;

  ~Grid();
  
  void setObserver(Observer<Info, State> *ob);
  std::vector<size_t> checkLines();
  void init();
  void clear();

  void addBlock(Block& b);
  std::vector<size_t> checkLines();
  void verifyMove(Block b, Move m);
  void verifyRotate(Block b, Rotate m);
  void drawBlock(Block b);
  void voidBlock(Block b);
  Level getLevel();
  int getScore();
  int getHiScore();
  Block getBlock(Level);
  bool isFull() const; 

  friend std::ostream &operator<<(std::ostream &out, const Grid &g);
};

#endif
