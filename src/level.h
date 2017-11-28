#ifndef LEVEL_H
#define LEVEL_H
#include <string>
#include "observer.h"
#include "subject.h"

// consider redesigning this class- maybe only Level 4 needs
//  to inherit the Observer class? 
class Level : public Observer<Info, State>{
public:
  virtual getBlock() = 0;
};

// Level 0 follows the sequence defined in sequence.txt
class Level0 : public Level{
  string sequence = s;
public:
  Level0(string s);
  getBlock();
};

// S & Z = 1/12, else 1/6
class Level1 : public Level{
public:
  getBlock();
};

// equal probability
class Level2 : public Level{
public:
  getBlock();
};

// S & Z = 2/9, else 1/9
// Add parameter to Block such that it's "heavy"
class Level3 : public Level{
public:
  getBlock();
};

// every 5 blocks, a 1x1 block is dropped in to the centre column
class Level4 : public Level{
public:
  void notify(Subject<Info, State> &whoFrom) override;
  getBlock();
};

#endif