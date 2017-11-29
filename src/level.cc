#include <string>
#include <cstdlib>
#include <fstream>
#include <time>
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

Block Level1::getBlock(){
  srand(time(NULL)); // reset seed
  int n = rand() % 12;
  if (n == 0){
    Block_S b;
    return b;
  } else if (n == 1){
    Block_Z b;
    return b;
  } else if (n >= 2 && n <= 3){
    Block_I b;
    return b;
  } else if (n >= 4 && n <= 5){
    Block_J b;
    return b;
  } else if (n >= 6 && n <= 7){
    Block_L b;
    return b;
  } else {
    Block_O b;
    return b;
  }
}

Block Level2::getBlock(){
  srand(time(NULL)); // reset seed
  int n = rand() % 6;
  if (n == 0){
    Block_S b;
    return b;
  } else if (n == 1){
    Block_Z b;
    return b;
  } else if (n == 2){
    Block_I b;
    return b;
  } else if (n == 3){
    Block_J b;
    return b;
  } else if (n == 4){
    Block_L b;
    return b;
  } else {
    Block_O b;
    return b;
  }
}