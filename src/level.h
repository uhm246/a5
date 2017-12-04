#ifndef LEVEL_H
#define LEVEL_H
#include <string>
#include <vector>
#include "observer.h"
#include "subject.h"
#include "block.h"
#include "state.h"

class Level{
  std::string sequence_file;
  int index;
  std::vector<char> sequence;
  int n;
  bool random = false;
  int seed = 0;
public:
  Level(std::string s);
  Block getBlock();
  int num();
  bool isRandom();
  void setSeed(int s);
  void setRandom(bool b);
};

/*
// every 5 blocks, a 1x1 block is dropped in to the centre column
class Level4 : public Level{
public:
  Level4();
  Block getBlock() override; 
};
*/
#endif
