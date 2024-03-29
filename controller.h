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
#include "starblock.h"
#include "textdisplay.h"
#include "graphics.h"


class Biquadris {
  // Fill in this class with your implementation
  int width, height;
  int score;
  int hiScore;
  int player;
  
  std::shared_ptr<Level> lev1;
  std::shared_ptr<Level> lev2;
  bool lose1 = false;
  bool lose2 = false;
  std::shared_ptr<TextDisplay> td;
  std::shared_ptr<Graphics> window;
  bool seqfile = false;
  std::string f;

  // You may build other classes and modules as well
  public:
  int seed;
  std::string f1, f2;
  bool graphics;
  Grid g1{}; // for player 1
  Grid g2{}; // for player 2
  //Biquadris();
  Biquadris(int width, int height, bool graphics);
  void run();
  int getCurScore();
  int getHighScore();
  void restartGame();
  void switchPlayer();
  void updateLevel();
  std::shared_ptr<Block> genNext(char c);
};

#endif