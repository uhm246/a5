#ifndef BLOCK_H
#define BLOCK_H
#include <vector>
#include "cell.h"

// abstract class
class Block : public Observer<Info, State>{
public:
  Block(); // initialize the observed cells in constructor
           // I need to refer back to my grid implementation
};

class Block_I : public Block{
public:
  void notify(Subject<Info, State> &whoFrom) override;
};

class Block_J : public Block{
  void notify(Subject<Info, State> &whoFrom) override;
};

class Block_L : public Block{
  void notify(Subject<Info, State> &whoFrom) override;
};

class Block_S : public Block{
  void notify(Subject<Info, State> &whoFrom) override;
};

class Block_Z : public Block{
  void notify(Subject<Info, State> &whoFrom) override;
};

class Block_O : public Block{
  void notify(Subject<Info, State> &whoFrom) override;
};

#endif