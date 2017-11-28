#ifndef BLOCK_H
#define BLOCK_H
#include <vector>
#include "cell.h"

class Block : public Observer<Info, State>{
public:
  Block(); // initialize the observed cells in constructor
           // I need to refer back to my grid implementation
};

#endif