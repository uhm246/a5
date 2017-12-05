#include <string>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include "observer.h"
#include "subject.h"
#include "level.h"
#include "block.h"

using namespace std;

Level::Level(){
  char b;
  ifstream file("sequnece");
  while (file >> b){
    sequence.push_back(b);
  }
}

void Level::setSequence(string s){
  ifstream file(s);
  sequence.clear();
  index = 0;
  char b;
  while (file >> b){
    sequence.push_back(b);
  }
}

Block Level::getBlock(){
  if (n == 0){
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
  } else if (n == 1){
    srand(seed); // reset seed
    int i = rand() % 12;
    if (i == 0){
      Block_S b;
      return b;
    } else if (i == 1){
      Block_Z b;
      return b;
    } else if (i >= 2 && i <= 3){
      Block_I b;
      return b;
    } else if (i >= 4 && i <= 5){
      Block_J b;
      return b;
    } else if (i >= 6 && i <= 7){
      Block_L b;
      return b;
    } else if (i >= 8 && i <= 9){
      Block_T b;
      return b;
    } else {
      Block_O b;
      return b;
    }
  } else if (n == 2){
    srand(seed); // reset seed
    int i = rand() % 7;
    if (i == 0){
      Block_S b;
      return b;
    } else if (i == 1){
      Block_Z b;
      return b;
    } else if (i == 2){
      Block_I b;
      return b;
    } else if (i == 3){
      Block_J b;
      return b;
    } else if (i == 4){
      Block_L b;
      return b;
    } else if (i == 5){
      Block_T b;
      return b;
    } else {
      Block_O b;
      return b;
    }
  } else if (n == 3){
    srand(seed);
    int i = rand() % 9;
    if (i >= 0 && i <= 1){
      Block_S b;
      return b;
    } else if (i >= 2 && i <= 3){
      Block_Z b;
      return b;
    } else if (i == 4){
      Block_I b;
      return b;
    } else if (i == 5){
      Block_J b;
      return b;
    } else if (i == 6){
      Block_L b;
      return b;
    } else if (i == 7){
      Block_T b;
      return b;
    } else {
      Block_O b;
      return b;
    }
  } else {
    Block b;
    return b;
  }
}

int Level::num(){
  return n;
}

bool Level::isRandom(){
  return random;
}

void Level::setSeed(int s){
  seed = s;
}

void Level::setRandom(bool b){
  random = b;
}

void Level::setLevel(int i){
  n = i;
}

void Level::increaseLevel(){
  if (n < 4){
    n++;
  }
}

void Level::decreaseLevel(){
  if (n > 0){
    n--;
  }
}


// For Level 4, I need to first implement whatever the "Controller" or
//  whatever Level 4 will be observing first before I can have a clear idea
//  of its implementation.