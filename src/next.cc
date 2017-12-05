#include "next.h"
#include "state.h"

using namespace std;

void Next::init(){
  theGrid.clear();
  theGrid.resize(this->height);
   for (int i = 0; i < this->height; ++i){
    for (int j = 0; j < this->width; ++j){
      theGrid[i].emplace_back(Cell(i,j));
    }
  }
  for (int i = 0; i < this->height; ++i){
    for (int j = 0; j < this->width; ++j){
      //theGrid[i][j].attach(td);
      //theGrid[i][j].attach(gd);
    }
  }
}

void Next::setNext(Block b){
  init();
  vector<vector<int>> v = b.getCoords(0, 0);
  Type t = b.getType();
  for (auto a : v){
    theGrid[a[0]][a[1]].setType(t);
  }
}