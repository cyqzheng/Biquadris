#ifndef __GRID_H__
#define __GRID_H__
#include <iostream>
#include <vector>
#include <memory>
#include "cell.h"

class Block;

class Grid {
  
  int gridRows;    // Number of rows in the grid.
  int gridCols;    // Number of columns in the grid.
  // TextDisplay *td; // The text display.
  // Add private members, if necessary.
  // Xwindow *window;
  
  void clearGrid();   // Frees the grid.

 public:
  int level = 0;
  int score = 0;
  int highscore = 0;
  int player = 0;
  bool noGraphics = true;
  std::vector<std::vector<Cell>> theGrid;  // The actual grid.
  std::shared_ptr<Block> b;
  std::shared_ptr<Block> nextb;
  Grid();
  Grid(int r, int c);
  ~Grid();
  
  bool isValidRotate(std::vector<Cell *> newpos);
  int remFullRows(); // returns number of removed rows
  bool isRowFull(int row) const;
  void clearRow(int row);
  bool isGameOver();
  void reset();
  int getLevel();
  Cell * getCell(int r, int c);
  void levelUp();
  void levelDown();
  //void updateScore(int rowsCleared);
  // void putBlock(int, int, Block);
  // void update(); // updates to the next level
};

#endif

// drop the Block
// switch players
// and get the next Block
// Block b;
// b = newBlock;
