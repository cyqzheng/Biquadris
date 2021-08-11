#ifndef __GRID_H__
#define __GRID_H__
#include <iostream>
#include <vector>
#include "cell.h"
#include "block.h"
#include "level.h"

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
  int score = 0;
  Block b;
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
  // void putBlock(int, int, Block);
  // void update(); // updates to the next level
};

#endif

// drop the Block
// switch players
// and get the next Block
// Block b;
// b = newBlock;
