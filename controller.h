#ifndef LIFEGAME_H_
#define LIFEGAME_H_
#include <iostream>
#include <vector>
#include <memory>
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
#include "block.h"

class Biquadris {
  // Fill in this class with your implementation
  int width, height;
  int score;
  int hiScore;
  int player;
  LevelZero lev{};
  bool lose1;
  bool lose2;

  // You may build other classes and modules as well
  Grid g1{}; // for player 1
  Grid g2{}; // for player 2
  public:
  Biquadris();
  Biquadris(int width=11, int height=18);
  void run();
  int getCurScore();
  int getHighScore();
  void restartGame();
  void switchPlayer();
  std::shared_ptr<Block> genNext(char c);
};

#endif