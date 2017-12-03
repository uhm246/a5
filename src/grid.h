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
  GraphicsDisplay *gd = nullptr;
  Observer<Info, State> *ob = nullptr; 
  
  void clearLine(size_t r);
  void clearLines();

  int score = 0;
  int hiscore = 0;
  Level lev;
  void resetScore();
  void increaseScore(int i);
  void setHiScore();
  std::vector<int> checkBlocks();
  std::vector<size_t> checkLines();
 public:

  const width = 11;
  const height = 18;

  ~Grid();
  
  void setObserver(Observer<Info, State> *ob);
  void init();

  void addBlock(Block& b);
  void verifyMove(Block b, Move m);
  void verifyRotate(Block b, Rotate m);
  void drawBlock(Block b);
  void voidBlock(Block b);
  void setBlock(Block b);
  Level& getLevel();
  void setLevel(Level l);
  int getScore();
  int getHiScore();

  friend std::ostream &operator<<(std::ostream &out, const Grid &g);
};

#endif
