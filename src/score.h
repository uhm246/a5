#ifndef SCORE_H
#define SCORE_H

class Score {
  int score = 0;
  int hiscore = 0;
public:
  void resetScore();
  void increaseScore(int i);
  void setHiScore();
  int getScore();
  int getHiScore();
};

#endif
