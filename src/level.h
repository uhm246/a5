#ifndef LEVEL_H
#define LEVEL_H
#include <string>

class Level : public Observer<Info, State>{
public:
  virtual getBlock() = 0;
};

class Level0 : public Level{
  string sequence = s;
public:
  Level0(string s);
  getBlock();
};

class Level1 : public Level{
public:
  getBlock();
};

class Level2 : public Level{
public:
  getBlock();
};

class Level3 : public Level{
public:
  getBlock();
};

class Level4 : public Level{
public:
  getBlock();
};

#endif