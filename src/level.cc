#include <string>
#include <cstdlib>
#include <fstream>
#include "observer.h"
#include "subject.h"
#include "level.h"
#include "block.h"

using namespace std;

Level0::Level0(string s): sequence_file(s), index(0){
  char b;
  ifstream file;
  while (file >> b){
    sequence.push_back(b);
  }
}

Block Level0::getBlock(){
  char block_id = sequence[index % sequence.size()];
  index++;
  // index should probably reset instead but we assume int overflow isn't real
  if (block_id == 'I'){
    Block_I b;
    return b;
  } else if (block_id == 'J'){
    Block_J b;
    return b;
  } else if (block_id == 'L'){
    Block_L b;
    return b;
  } else if (block_id == 'S'){
    Block_S b;
    return b;
  } else if (block_id == 'Z'){
    Block_Z b;
    return b;
  } else {
    Block_O b;
    return b;
  }
}