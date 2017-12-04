#ifndef TEXTDISPLAY_H
#define TEXTDISPLAY_H
#include <iostream>
#include <vector>
#include <string>
#include "observer.h"
#include "subject.h"
#include "state.h"
class Cell;

class TextDisplay: public Observer<State> {
  std::vector<std::string> theDisplay;
  const int gridWidth = 11;
  const int gridHeight = 18;
  int level;
  int score;
  int hiscore;
 public:
  TextDisplay(int level, int score, int hiScore);

  void notify(Subject<State> &whoFrom) override;

  friend std::ostream &operator<<(std::ostream &out, const TextDisplay &td);
};
#endif
