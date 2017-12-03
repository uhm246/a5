#ifndef GRID_H
#define GRID_H
#include <iostream>
#include <vector>
#include <cstddef>
#include "cell.h"
#include "state.h"
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
  void addBlock(Block& b);
  std::vector<int> checkBlocks();
  std::vector<size_t> checkLines();
 public:

  const width = 11;
  const height = 18;

  ~Grid();
  
  void setObserver(Observer<Info, State> *ob);

  // Initialize board, also clears it
  void init();

  // Verify that a move is valid
  bool verifyMove(Block b, Move m, size_t r, size_t c);

  // Verify that a rotate is valid
  bool verifyRotate(Block b, Rotate m, size_t r, size_t c);

  // Draw a block on board (this is a Temp block)
  void drawBlock(Block b, size_t r, size_t c);

  // Undraw the block
  void voidBlock(Block b, size_t r, size_t c);

  // Set the block in stone in said location (this is a Solid block)
  void setBlock(Block b, size_t r, size_t c);

  // Get current level
  Level& getLevel();

  // Set current level
  void setLevel(Level l);

  // Get current score
  int getScore();

  // Get hi score
  int getHiScore();

  friend std::ostream &operator<<(std::ostream &out, const Grid &g);
};

#endif
