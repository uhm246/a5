#ifndef GRID_H
#define GRID_H
#include <iostream>
#include <vector>
#include <cstddef>
#include "cell.h"
#include "state.h"
#include "block.h"
#include "level.h"
#include "textdisplay.h"
#include "graphicsdisplay.h"
#include "score.h"

class Grid {
  
  std::vector<std::vector<Cell>> theGrid;
  std::vector<Block*> blocks;
  TextDisplay *td = nullptr;
  Score score;
  GraphicsDisplay *gd = nullptr;
  Observer<State> *ob = nullptr; 
  
  void clearLine(size_t r);
  void clearLines();

  int seed = 0;
  bool textmode = false;
  bool seq = false;
  int seqind = 0;
  void addBlock(Block* b);
  std::vector<int> checkBlocks();
  std::vector<size_t> checkLines();

  Level level;
 
 public:

  const int width = 11;
  const int height = 18;
  
  ~Grid();
  
  void setObserver(Observer<State> *ob);

  // Initialize board, also clears it
  void init();

  // Verify that a move is valid
  bool verifyMove(Block b, Move m, size_t r, size_t c);

  // Verify that a rotate is valid
  bool verifyRotate(Block b, Rotate m, size_t r, size_t c);

  // Verify that a block switch is valid
  bool verifySwitch(Block b, size_t r, size_t c);

  // Draw a block on board (this is a Temp block)
  void drawBlock(Block b, size_t r, size_t c);

  // Undraw the block
  void voidBlock(Block b, size_t r, size_t c);

  // Set the block in stone in said location (this is a Solid block)
  void setBlock(Block b, size_t r, size_t c);

  // Aggregate the number of 'holes' below specified
  int checkHoles(size_t r, size_t c, size_t width, size_t depth);

  // Get current level
  Level& getLevel();

  Score& getScoreObject();

  // Get current score
  int getScore();

  // Get hi score
  int getHiScore();

  // Set seed
  void setSeed(int s);

  // Set TextMode
  void setTextMode(bool b);

  // Get sequence mode
  bool getSeq();

  // Set sequnece mode
  void setSeq(bool b);

  // Get sequence index
  int getSeqInd();

  // Set sequence index
  void setSeqInd(int n);

  // Increment sequence index
  void incrementSeqInd();

  void setGraphicsDisplay(GraphicsDisplay *g);
  void setTextDisplay(TextDisplay *t);


  friend std::ostream &operator<<(std::ostream &out, const Grid &g);
};

#endif
