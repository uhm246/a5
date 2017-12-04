#include <string>
#include <cstdlib>
#include <fstream>
#include "observer.h"
#include "subject.h"
#include "level.h"
#include "block.h"

using namespace std;

int Level::num(){
  return n;
}

Level0::Level0(string s): sequence_file(s), index(0){
  n = 0;
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
  } else if (block_id == 'T'){
    Block_T b;
    return b;
  } else {
    Block_O b;
    return b;
  }
}

Level1::Level1(){
  n = 1;
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
  } else if (n >= 8 && n <= 9){
    Block_T b;
    return b;
  } else {
    Block_O b;
    return b;
  }
}

Level2::Level2(){
  n = 2;
}

Block Level2::getBlock(){
  srand(time(NULL)); // reset seed
  int n = rand() % 7;
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
  } else if (n == 5){
    Block_T b;
    return b;
  } else {
    Block_O b;
    return b;
  }
}

Level3::Level3(){
  n = 3;
}

Block Level3::getBlock(){
  srand(time(NULL));
  int n = rand() % 9;
  if (n >= 0 && n <= 1){
    Block_S b;
    b.toggleHeavy();
    return b;
  } else if (n >= 2 && n <= 3){
    Block_Z b;
    b.toggleHeavy();
    return b;
  } else if (n == 4){
    Block_I b;
    b.toggleHeavy();
    return b;
  } else if (n == 5){
    Block_J b;
    b.toggleHeavy();
    return b;
  } else if (n == 6){
    Block_L b;
    b.toggleHeavy();
    return b;
  } else if (n == 7){
    Block_T b;
    b.toggleHeavy();
    return b;
  } else {
    Block_O b;
    b.toggleHeavy();
    return b;
  }
}

// For Level 4, I need to first implement whatever the "Controller" or
//  whatever Level 4 will be observing first before I can have a clear idea
//  of its implementation.