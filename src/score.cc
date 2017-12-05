#include "score.h"

void Score::resetScore(){
  setHiScore();
  score = 0;
}

void Score::setHiScore(){
  if (score > hiscore){
    hiscore = score;
  }
}

void Score::increaseScore(int i){
  score += i;
}

int Score::getScore(){
  return score;
}

int Score::getHiScore(){
  return hiscore;
}
