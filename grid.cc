#include <iostream>
#include "grid.h"

using namespace std;

 Grid::Grid() { 
  //td = nullptr;
  gridRows = 15;
  gridCols = 11;
  level = 0;
  score = 0;
}

Grid::Grid(int r, int c) {
  gridRows = r;
  gridCols = c;
  level = 0;
  score = 0;
}

Grid::~Grid() { 
  theGrid.clear(); // clear all elements in the vector
  //delete td; // delete the pointer
  }

void Grid::clearGrid() { 
  theGrid.clear(); // clear all elements in the vector
  gridRows = 0;
  gridCols = 0;
  level = 0;
 }

 bool Grid::isRowFull() const {
   std::vector<Cell> rows = theGrid[0];
   bool full = true;
   for(int i = 0; i < gridCols; i++) {
     if(rows[i].getType() == 'e') full = false;
   }
   return full;
 }

  void Grid::clearRow() {
  //   // set the bottom row to empty
  //   std::vector<Cell> rows = theGrid[0];
  //   for(int i = 0; i < gridCols; i++) {
  //     rows[i].setType('e');
  //  }
   // move all otheer cells down a row
   for(int i = 1; i < gridRows; i++) {
     for(int j = 0; j < gridCols; j++) {
       theGrid[i][j].setRow(i-1);
     }
   }
  }

  bool Grid::isGameOver() {
    std::vector<Cell> topRow = theGrid[gridRows-1];
    std::vector<Cell> secondRow = theGrid[gridRows-2];
    int counter = 0;
    for(int i = 0; i < gridCols; i++) {
      if(topRow[i].getType() != 'e') ++counter;
    }
    if(counter == 15) return true;
    return false;
  }

  void Grid::reset() {
    for(int i = 1; i < gridRows; i++) {
     for(int j = 0; j < gridCols; j++) {
       theGrid[i][j].setType('e');
     }
   }
  }

//  void Grid::update() {
//     ++score;
//     vector<vector<bool>> values; // holds the life values of the cells
//     for(int i = 0; i < gridRows; i++) { // initialize it
//         values.emplace_back(vector<bool>());
//         for(int j = 0; j < gridCols; j++) values[i].emplace_back(false);
//     }
//     // store the updated life values
//     for(int i = 0; i < gridRows; i++) {
//         for(int j = 0; j < gridCols; j++) {
//             values[i][j] = theGrid[i][j]->updateLife(totalNeighbours(i, j, vec), gen);
//         }
//     }

//     // apply the updates
//     for(int i = 0; i < height; i++) {
//         for(int j = 0; j < gridCols; j++) {
//             theGrid[i][j]->setLife(values[i][j]);
//         }
//     }

//     // clear values
//     for(int i = 0; i < gridRows; i++) {
//         for(int j = 0; j < gridCols; j++) {
//             values[i].clear();
//         }
//     }
//     values.clear();
// }

  
  int Grid::getLevel() { return level; }

  std::vector<std::vector<Cell>> Grid::getCells() { return theGrid; }

  Cell Grid::getCell(int r, int c) { return theGrid[r][c]; }

  int Grid::getLevel() { return level; }

  void Grid::levelUp() { ++level; }

  void Grid::levelDown() { --level; }
