#ifndef LIFEGAME_H_
#define LIFEGAME_H_
#include <iostream>
#include <vector>
#include "cell.h"
#include "grid.h"

class Biquadris {
  // Fill in this class with your implementation
  int width, height;
  int score;
  int hiScore;
  int player;
  // You may build other classes and modules as well
  Grid g;
  public:
  Biquadris(int width, int height);
  void run();
  int getCurScore();
  int getHighScore();
  void restartGame();
  void switchPlayer();
};

#endif