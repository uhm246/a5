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
  int index = 0;
  std::vector<char> sequence;
  int n = 1;
  bool random = false;
  int seed = 0;
  int lvl4count = 0;
public:
  Level();
  Block getBlock();
  int num();
  bool isRandom();
  void setSeed(int s);
  void setRandom(bool b);
  void setLevel(int i);
  void setSequence(std::string s);
  void increaseLevel();
  void decreaseLevel();
  void resetlvl4count();
  void increaselvl4count();
  int getlvl4count();
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
