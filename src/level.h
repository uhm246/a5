#ifndef LEVEL_H
#define LEVEL_H
#include <string>
#include "observer.h"
#include "subject.h"
#include "block.h"
#include "info.h"
#include "state.h"

class Level{
public:
  virtual Block getBlock() = 0;
};

// Level 0 follows the sequence defined in sequence.txt
class Level0 : public Level{
  std::string sequence_file;
  int index;
  std::vector<char> sequence;
public:
  Level0(std::string s);
  Block getBlock() override;
};

// S & Z = 1/12, else 1/6
class Level1 : public Level{
public:
  Block getBlock() override;
};

// equal probability
class Level2 : public Level{
public:
  Block getBlock() override;
};

// S & Z = 2/9, else 1/9
// Add parameter to Block such that it's "heavy"
class Level3 : public Level{
public:
  Block getBlock() override;
};

// every 5 blocks, a 1x1 block is dropped in to the centre column
class Level4 : public Level, public Observer<State>{
public:
  void notify(Subject<Info, State> &whoFrom) override;
  Block getBlock() override; 
};

#endif