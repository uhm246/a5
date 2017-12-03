#include "grid.h"
#include "textdisplay.h"

using namespace std;

void Grid::clearLine(size_t r){
  for (size_t i = 0; i < this->width; i++){
    if (theGrid[r][i].getState().status == Status::Solid){
      theGrid[r][i].getBlock().removeCell(r, i);
    }
    theGrid[r][i].setStatus(Status::Empty);
  }
  for (size_t i = r+1; i < this->height - 1; i++){ //maybe adjust more
    for (size_t j = 0; j < this->width; j++){
      Info aboveinfo = theGrid[i+1][j].getState();
      Status abovestatus = aboveinfo.status;
      Type abovetype = aboveinfo.type;
      if (abovestatus != Status::Temp){
        theGrid[i][j].setStatus(abovestatus);
        theGrid[i][j].setType(abovetype);
      }
    }
  }
}

void Grid::clearLines(){
  vector<size_t> v = checkLines();
  increaseScore((v.size() + getLevel().num()) *
                (v.size() + getLevel().num()));
  checkBlocks();
}

void Grid::resetScore(){
  setHiScore();
  score = 0;
}

void Grid::setHiScore(){
  if (score > hiscore){
    hiscore = score;
  }
}

void Grid::increaseScore(int i){
  score += i;
}

vector<int> Grid::checkBlocks(){
  vector<int> idxs;
  for (int i = 0; i < blocks.size(); i++){
    if (blocks[i].getSize() == 0){
      int l = blocks[i].getLevel();
      increaseScore((l + 1) * (l + 1));
      idxs.push_back(i);
    }
  }
  for (int i = idxs.size() - 1; i >= 0; i--){ // check this actually works
    blocks.erase(blocks.begin() + i);
  }
}

bool checkLine(vector<Cell>& v, r){
  for (auto a : v){
    if (a.getState().status != Status::Solid){
      return false;
    }
  }
  return true;
}

vector<size_t> Grid::checkLines(){
  vector<size_t> v;
  for (size_t r = 0; r < this->height; r++){
    if (checkLine(theGrid[r])){
      v.push_back(r);
    }
  }
}

void Grid::init(){
  td = new TextDisplay();
  gd = new GraphicsDisplay();
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
      theGrid[i][j].attach(gd);
    }
  }
}

void addBlock(Block& b){
  blocks.push_back(b);
}

bool Grid::verifyMove(Block b, Move m){
  vector<vector<int>>& v = b.getCoords();
  switch m:
    case Move::Down:
      for (auto a : v){
        if (a[1] > 0){
          Info i = theGrid[a[0]][a[1]-1].getState();
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

bool Grid::verifyRotate(Block b, Rotate r){

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
  clearLines();
}

Level& getLevel(){
  return lev;
}

void setLevel(Level l){
  lev = l;
}

int getScore(){
  return score;
}

int getHiScore(){
  return hiscore;
}

