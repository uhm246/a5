#include <iostream>
#include "textdisplay.h"

using namespace std;

TextDisplay::TextDisplay(int level, int score, int hiScore){
  theDisplay.resize(18);
  for (int i = 0; i < 18; ++i){
    for (int j = 0; j < 11; ++j){
      theDisplay[i].push_back('-');
    }
  }
}

void TextDisplay::notify(Subject<State> &whoFrom){
	State s = whoFrom.getState();
	BlockType blocktype = s.blocktype;
	Type cellType = s.type;
	Status status = s.status;
	size_t col = s.c;
	size_t row = s.r;

	if (s.status == Status::Empty){
		theDisplay[row][col] = '-';
	} else if (s.status == Status::Temp) {
		theDisplay[row][col] = 'T';
	} else if (s.status == Status::Solid){
    theDisplay[row][col] = 'S';
  }
}

ostream &operator<<(ostream &out, const TextDisplay &td){
  for (int i = 17; i >= 0; --i){
    for (int j = 0; j < 11; ++j){
      out << td.theDisplay[i][j];
    }
    out << endl;
  }
  return out;
}