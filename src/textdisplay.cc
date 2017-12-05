#include <iostream>
#include "textdisplay.h"

using namespace std;

TextDisplay::TextDisplay(Score* score, Level* level): 
score(score), level(level){
  theDisplay.resize(18);
  for (int i = 0; i < 18; ++i){
    for (int j = 0; j < 11; ++j){
      theDisplay[i].push_back(' ');
    }
  }
}

void TextDisplay::notify(Subject<State> &whoFrom){
	State s = whoFrom.getState();
	BlockType blocktype = s.blocktype;
	Type cellType = s.type;
	Fill status = s.status;
	size_t col = s.c;
	size_t row = s.r;
  if (true){ // s.blocktype == BlockType::Current){
    if (s.status == Fill::Solid){
      switch(cellType){
        case Type::Single:
          theDisplay[row][col] = '*';
        case Type::I:
          theDisplay[row][col] = 'I';
        case Type::J:
          theDisplay[row][col] = 'J';
        case Type::L:
          theDisplay[row][col] = 'L';
        case Type::S:
          theDisplay[row][col] = 'S';
        case Type::Z:
          theDisplay[row][col] = 'Z';
        case Type::O:
          theDisplay[row][col] = 'O';
        case Type::T:
          theDisplay[row][col] = 'T';
        default:
          theDisplay[row][col] = '?';
      }
    } else if (s.status == Fill::Temp){
      theDisplay[row][col] = 'N';
    } else if (s.status == Fill::Empty){
      theDisplay[row][col] = ' ';
    }
  }
}

ostream &operator<<(ostream &out, const TextDisplay &td){
  out << "Level: " << td.level->num() << endl;
  out << "Score: " << td.score->getScore() << endl;
  out << "Hi Score: " << td.score->getHiScore() << endl;
  out << "-----------" << endl;
  for (int i = 17; i >= 0; --i){
    for (int j = 0; j < 11; ++j){
      out << td.theDisplay[i][j];
    }
    out << endl;
  }
  out << "-----------" << endl;
  return out;
}