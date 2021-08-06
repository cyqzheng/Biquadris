#ifndef __GRID_H__
#define __GRID_H__
#include <iostream>
#include <vector>
#include "cell.h"
//#include "block.h"

class Grid {
  std::vector<std::vector<Cell>> theGrid;  // The actual grid.
  int gridRows;    // Number of rows in the grid.
  int gridCols;    // Number of columns in the grid.
  int level;
  // bool won;        // Grid in winning state
  // TextDisplay *td; // The text display.
  // Add private members, if necessary.
  // Xwindow *window;

  void clearGrid();   // Frees the grid.

 public:
  Grid();
  Grid(int r, int c);
  ~Grid();
  
  bool isValidRotate(std::vector<Cell>);
  bool isRowFull() const;
  void clearRow();
  bool isGameOver();
  void reset();
  int getLevel();
  std::vector<std::vector<Cell>> getCells();
  Cell getCell(int r, int c);
  void levelUp();
  void levelDown();
  //void putBlock(int, int, Block);

};

#endif
