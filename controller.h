#ifndef LIFEGAME_H_
#define LIFEGAME_H_
#include <iostream>
#include <vector>
#include "cell.h"
#include "grid.h"
#include "controller.h"
#include "cell.h"
#include "levelzero.h"
#include "levelone.h"
#include "leveltwo.h"
#include "levelthree.h"
#include "levelfour.h"
#include "iblock.h"
#include "jblock.h"
#include "lblock.h"
#include "oblock.h"
#include "sblock.h"
#include "tblock.h"
#include "zblock.h"

class Biquadris {
  // Fill in this class with your implementation
  int width, height;
  int score;
  int hiScore;
  int player;
  LevelZero lev;

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