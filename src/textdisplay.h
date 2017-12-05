#ifndef TEXTDISPLAY_H
#define TEXTDISPLAY_H
#include <iostream>
#include <vector>
#include <string>
#include "observer.h"
#include "subject.h"
#include "state.h"
#include "score.h"
#include "level.h"
class Cell;

class TextDisplay: public Observer<State> {
  std::vector<std::string> theDisplay;
  Score* score;
  Level* level;
 public:
  TextDisplay(Score* score, Level* level);
  void notify(Subject<State> &whoFrom) override;

  friend std::ostream &operator<<(std::ostream &out, const TextDisplay &td);
};
#endif
