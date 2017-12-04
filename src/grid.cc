#include "grid.h"

using namespace std;

void Grid::clearLine(size_t r){
  for (size_t i = 0; i < this->width; i++){
    if (theGrid[r][i].getState().status == Status::Solid){
      theGrid[r][i].getBlock()->removeCell(r, i);
    }
    theGrid[r][i].setStatus(Status::Empty);
  }
  for (size_t i = r+1; i < this->height - 1; i++){ //maybe adjust more
    for (size_t j = 0; j < this->width; j++){
      State aboveinfo = theGrid[i+1][j].getState();
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

void Grid::addBlock(Block* b){
  blocks.push_back(b);
}

vector<int> Grid::checkBlocks(){
  vector<int> idxs;
  for (int i = 0; i < blocks.size(); i++){
    if (blocks[i]->getSize() == 0){
      int l = blocks[i]->getLevel();
      increaseScore((l + 1) * (l + 1));
      idxs.push_back(i);
    }
  }
  for (int i = idxs.size() - 1; i >= 0; i--){ // check this actually works
    blocks.erase(blocks.begin() + i);
  }
  return idxs;
}

bool checkLine(vector<Cell>& v){
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
  return v;
}

void Grid::init(){
  resetScore();
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
      //theGrid[i][j].attach(gd);
    }
  }
}

bool Grid::verifyMove(Block b, Move m, size_t r, size_t c){
  vector<vector<int>> v = b.getCoords(r, c); 
  switch (m){
    case Move::Down:
      for (auto a : v){
        if (a[1] > 0){
          State i = theGrid[a[0]][a[1]-1].getState();
          if (i.status == Status::Solid){
            return false;
          }
        } else {
          return false;
        }
      }
      return true;
    case Move::Right:
      for (auto a : v){
        if (a[0] < this->width){
          State i = theGrid[a[0]+1][a[1]].getState();
          if (i.status == Status::Solid){
            return false;
          }
        } else {
          return false;
        }
      }
      return true;
    case Move::Left:
      for (auto a : v){
        if (a[0] > 0){
          State i = theGrid[a[0]-1][a[1]].getState();
          if (i.status == Status::Solid){
            return false;
          }
        } else {
          return false;
        }
      }
      return true;
    default: 
      return false;
    }
}

bool Grid::verifyRotate(Block b, Rotate m, size_t r, size_t c){
  vector<vector<int>> v = b.getRotatedCoords(r, c, m);
  for (auto a : v){
    if (a[1] > 0 && a[0] > 0 && a[0] < this->width){
      State i = theGrid[a[0]][a[1]].getState();
      if (i.status == Status::Solid){
        return false;
      }
    } else {
      return false;
    }
  }
  return true;
}

bool Grid::verifySwitch(Block b, size_t r, size_t c){
  vector<vector<int>> v = b.getCoords(r, c);
  for (auto a : v){
    if (a[1] > 0 && a[0] > 0 && a[0] < this->width){
      State i = theGrid[a[0]][a[1]].getState();
      if (i.status == Status::Solid){
        return false;
      }
    } else {
      return false;
    }
  }
  return true;
}

void Grid::drawBlock(Block b, size_t r, size_t c){
  vector<vector<int>> v = b.getCoords(r, c);
  for (auto a : v){
    theGrid[a[0]][a[1]].setStatus(Status::Temp);
    theGrid[a[0]][a[1]].setType(b.getType());
  }
}

void Grid::voidBlock(Block b, size_t r, size_t c){
  vector<vector<int>> v = b.getCoords(r, c);
  for (auto a : v){
    theGrid[a[0]][a[1]].setStatus(Status::Empty);
  }
}

void Grid::setBlock(Block b, size_t r, size_t c){
  vector<vector<int>> v = b.getCoords(r, c);
  for (auto a : v){
    theGrid[a[0]][a[1]].setStatus(Status::Solid);
    theGrid[a[0]][a[1]].setBlock(&b);
  }
  clearLines();
  addBlock(&b);
}

int Grid::checkHoles(size_t r, size_t c, size_t width, size_t depth){
  int holes = 0;
  for (int i = 0; i < depth; i++){
    bool not_zero = true;
    if (not_zero){
      for (int j = r; j < r + width; j++){
        if (r < this->width && 
            theGrid[r - depth - 1][j].getState().status == Status::Empty){
          holes++;
        }
      }
      if (r - depth - 1 == 0) not_zero = false;
    }
  }
  return holes;
}

Level& Grid::getLevel(){
  return lev;
}

void Grid::setLevel(Level l){
  lev = l;
}

int Grid::getScore(){
  return score;
}

int Grid::getHiScore(){
  return hiscore;
}

void Grid::setTextDisplay(TextDisplay *t){
  td = t;
}
