#ifndef SCORE_H
#define SCORE_H

class Score {
  int score;
  int hiscore;
public:
  void resetScore();
  void increaseScore(int i);
  void setHiScore();
  int getScore();
  int getHiScore();
};

#endif
