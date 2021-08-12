#ifndef __TEXTDISPLAY_H__
#define __TEXTDISPLAY_H__
#include <iostream>
#include <vector>
#include "observer.h"
#include "subject.h"
#include "grid.h"

class Cell;

class TextDisplay: public Observer {
  std::vector<std::vector<char>> play1;
  std::vector<std::vector<char>> play2;
  const int rows;
  const int cols;
 public:
  TextDisplay(int rows, int columns);
  void showText(Grid * g1, Grid * g2);

  void notify(Cell &whoNotified) override;
  virtual std::string getName() const override;

  ~TextDisplay();

  friend std::ostream &operator<<(std::ostream &out, const TextDisplay &td);
};

#endif

