#include "grid.h"
#include "textdisplay.h"

void Grid::init(){
  td = new TextDisplay();
  occupied = 4;
  capacity = n*n;
  theGrid.clear();
  theGrid.resize(this->height);
  for (size_t i = 0; i < this->height; ++i){
    for (size_t j = 0; j < this->width; ++j){
      theGrid[i].emplace_back(Cell(i,j));
    }
  }
  for (size_t i = 0; i < this->height; ++i){
    for (size_t j = 0; j < this->width; ++j){
      theGrid[i][j].attach(td);
    }
  }
}

bool Grid::verifyMove(Block b, Move m){
  vector<vector<int>>& v = b.getCoords();
  switch m:
    case Move::Down:
      for (auto a : v){
        if (a[1] > 0){
          Info i = theGrid[a[0]][a[1]-1].getInfo();
          return i.status != Status::Solid;
        } else {
          return false;
        }
      }
    case Move::Right:
      for (auto a : v){
        if (a[0] < this->width){
          Info i = theGrid[a[0]+1][a[1]];
          return i.status != Status::Solid;
        } else {
          return false;
        }
      }
    case Move::Left:
      for (auto a : v){
        if (a[0] > 0){
          Info i = theGrid[a[0]-1][a[1]];
          return i.status != Status::Solid;
        } else {
          return false;
        }
      }
    default: 
      return false;
}

void Grid::drawBlock(Block b){
  vector<vector<int>>& v = b.getCoords();
  for (auto a : v){
    theGrid[a[0]][a[1]].setStatus(Status::Temp);
    theGrid[a[0]][a[1]].setType(b.getType());
  }
}

void Grid::voidBlock(Block b){
  vector<vector<int>>& v = b.getCoords();
  for (auto a : v){
    theGrid[a[0]][a[1]].setStatus(Status::Empty);
  }
}

void Grid::setBlock(Block b){
  vector<vector<int>>& v = b.getCoords();
  for (auto a : v){
    theGrid[a[0]][a[1]].setStatus(Status::Solid);
  }
}

void Grid::clearLine(size_t r){
  for (auto a : theGrid[r]){
    a.setStatus(Status::Empty);
  }
  for (size_t i = r+1; i < this->height - 1; i++){ //maybe adjust more
    for (size_t j = 0; j < this->width; j++){
      Info aboveinfo = theGrid[i+1][j].getInfo();
      Status abovestatus = aboveinfo.status;
      Type abovetype = aboveinfo.type;
      if (abovestatus != Status::Temp){
        theGrid[i][j].setStatus(abovestatus);
        theGrid[i][j].setType(abovetype);
      }
    }
  }
}

bool checkLine(vector<Cell>& v, r){
  for (auto a : v){
    if (a.getInfo().status != Status::Solid){
      return false;
    }
  }
  return true;
}

void Grid::checkLines(){
  for (size_t r = 0; r < this->height; r++){
    if (checkLine(theGrid[r])){
      clearLine(r);
    }
  }
}