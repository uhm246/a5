#include "grid.h"

using namespace std;

Grid::~Grid(){
  
}

void Grid::clearLine(size_t r){
  for (int i = 0; i < this->width; i++){
    if (theGrid[r][i].getState().status == Fill::Solid){
      theGrid[r][i].getBlock()->removeCell(r, i);
    }
    theGrid[r][i].setStatus(Fill::Empty);
  }
  for (int i = r; i < this->height - 1; i++){ //maybe adjust more
    for (int j = 0; j < this->width; j++){
      State aboveinfo = theGrid[i+1][j].getState();
      Fill abovestatus = aboveinfo.status;
      Type abovetype = aboveinfo.type;
      if (abovestatus != Fill::Temp){
        theGrid[i][j].setStatus(abovestatus);
        theGrid[i][j].setType(abovetype);
      }
    }
  }
}

void Grid::clearLines(){
  vector<size_t> v = checkLines();
  int i = 0;
  for (auto a : v){
    clearLine(a-i);
    i++;
  }
  score.increaseScore((v.size() + getLevel().num()) *
                      (v.size() + getLevel().num()));
  checkBlocks();
}

void Grid::addBlock(Block* b){
  blocks.push_back(b);
}

vector<int> Grid::checkBlocks(){
  vector<int> idxs;
  int bsize = blocks.size();
  for (int i = 0; i < bsize; i++){
    if (blocks[i]->getSize() == 0){
      int l = blocks[i]->getLevel();
      score.increaseScore((l + 1) * (l + 1));
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
    if (a.getState().status != Fill::Solid){
      return false;
    }
  }
  return true;
}

vector<size_t> Grid::checkLines(){
  vector<size_t> v;
  for (int r = 0; r < this->height; r++){
    if (checkLine(theGrid[r])){
      v.push_back(r);
    }
  }
  return v;
}

void Grid::init(){
  score.resetScore();
  theGrid.clear();
  theGrid.resize(this->height);
  for (int i = 0; i < this->height; ++i){
    for (int j = 0; j < this->width; ++j){
      theGrid[i].emplace_back(Cell(i,j));
    }
  }
  for (int i = 0; i < this->height; ++i){
    for (int j = 0; j < this->width; ++j){
      theGrid[i][j].attach(td);
      theGrid[i][j].notifyObservers();
      //theGrid[i][j].attach(gd);
    }
  }
}

bool Grid::verifyMove(Block b, Move m, size_t r, size_t c){
  vector<vector<int>> v = b.getCoords(r, c); 
  switch (m){
    case Move::Down:
      for (auto a : v){
        if (a[0] > 0){
          State i = theGrid[a[0]-1][a[1]].getState();
          if (i.status == Fill::Solid){
            return false;
          }
        } else {
          return false;
        }
      }
      return true;
    case Move::Right:
      for (auto a : v){
        if (a[1] < this->width - 1){
          State i = theGrid[a[0]][a[1]+1].getState();
          if (i.status == Fill::Solid){
            return false;
          }
        } else {
          return false;
        }
      }
      return true;
    case Move::Left:
      for (auto a : v){
        if (a[1] > 0){
          State i = theGrid[a[0]][a[1]-1].getState();
          if (i.status == Fill::Solid){
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
    if (a[0] >= 0 && a[1] >= 0 && a[1] < this->width){
      State i = theGrid[a[0]][a[1]].getState();
      if (i.status == Fill::Solid){
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
    if (a[0] > 0 && a[1] > 0 && a[1] < this->width){
      State i = theGrid[a[0]][a[1]].getState();
      if (i.status == Fill::Solid){
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
    theGrid[a[0]][a[1]].setStatus(Fill::Temp);
    theGrid[a[0]][a[1]].setType(b.getType());
  }
}

void Grid::drawHint(Block b, size_t r, size_t c){
  vector<vector<int>> v = b.getCoords(r, c);
  for (auto a : v){
    theGrid[a[0]][a[1]].setStatus(Fill::Hint);
    theGrid[a[0]][a[1]].setType(b.getType());
  }
}

void Grid::voidBlock(Block b, size_t r, size_t c){
  vector<vector<int>> v = b.getCoords(r, c);
  for (auto a : v){
    theGrid[a[0]][a[1]].setStatus(Fill::Empty);
  }
}

void Grid::setBlock(Block b, size_t r, size_t c){
  vector<vector<int>> v = b.getCoords(r, c);
  for (auto a : v){
    theGrid[a[0]][a[1]].setType(b.getType());
    theGrid[a[0]][a[1]].setStatus(Fill::Solid);
    theGrid[a[0]][a[1]].setBlock(&b);
  }
  clearLines();
  addBlock(&b);
}

int Grid::checkHoles(size_t r, size_t c, size_t width, size_t depth){
  int holes = 0;
  int rint = r;
  int cint = c;
  int wint = width;
  int dint = depth;
  for (int i = 0; i < dint; i++){
    for (int j = cint; j < cint + wint; j++){
      if (cint < this->width && rint - i > 0 &&
        theGrid[r - i - 1][j].getState().status == Fill::Empty){
        holes++;
      }
    }
    
  }
  return holes;
}

Level& Grid::getLevel(){
  return level;
}

Score& Grid::getScoreObject(){
  return score;
}

int Grid::getScore(){
  return score.getScore();
}

int Grid::getHiScore(){
  return score.getHiScore();
}

void Grid::setSeed(int s){
  seed = s;
}

void Grid::setTextMode(bool b){
  textmode = b;
}

bool Grid::getSeq(){
  return seq;
}

void Grid::setSeq(bool b){
  seq = b;
}

int Grid::getSeqInd(){
  return seqind;
}

void Grid::setSeqInd(int n){
  seqind = n;
}

void Grid::incrementSeqInd(){
  seqind++;
}

void Grid::setTextDisplay(TextDisplay *t){
  td = t;
}

void Grid::setGraphicsDisplay(GraphicsDisplay *g){
  gd = g;
}

ostream &operator<<(ostream &out, const Grid &g){
  out << *g.td;
  return out;
}
