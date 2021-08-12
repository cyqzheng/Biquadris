#include <iostream>
#include "grid.h"
#include "starblock.h" 

using namespace std;

 Grid::Grid() { 
  //td = nullptr;
  gridRows = 18;
  gridCols = 11;
  level = 0;
  score = 0;

  // create the grid of cells
  for (int i=0; i<gridRows; ++i){
    theGrid.push_back(std::vector<Cell>());
    for (int j=0; j<gridCols; ++j){
      theGrid[i].push_back(Cell{i,j});
    }
  }
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


int Grid::remFullRows(){
  int num=0;
  for (int i=0; i<gridRows; ++i){
    if(isRowFull(i)){
      while(isRowFull){
        clearRow(i);
        ++num;
      }
    }
  }
  score += (level + num)*(level+num);
  if (score > highscore) highscore = score;
  return num;
}

 bool Grid::isRowFull(int row) const {
   if (row >= gridRows) return false;
   std::vector<Cell> rows = theGrid[row];
   bool full = true;
   for(int i = 0; i < gridCols; i++) {
     if(rows[i].getType() == 'e') full = false;
   }
   return full;
 }

void Grid::clearRow(int row) {
    if (row >= gridRows) return;

    // remove block's pointer to cell
    // set isblock state to false
    // if score is added, remBlock will return positive integer
    for (int j=0; j < gridCols; ++j){
      score += theGrid[row][j].remBlock();
      if (score > highscore) highscore = score;
    }
 
   // move all other blocks down a row
   for(int i = row; i > 1; i--) {
     for(int j = 0; j < gridCols; j++) {
       if (theGrid[i-1][j].getState()){ // if a block exists in row above
         theGrid[i][j].setBlock(theGrid[i-1][j].thisblock); // replace it
       }
     }
   }
   //reset top row
   for (int j=0; j < gridCols; ++j){
     theGrid[0][j].remBlock();
     theGrid[0][j].setType('e');
   }
  }

  bool Grid::isGameOver() {
    std::vector<Cell> topRow = theGrid[3];
    int counter = 0;
    for(int i = 0; i < gridCols; i++) {
      if(topRow[i].getType() == 'e') return true;
    }
    return false;
  }

  void Grid::reset() {
    for(int i = 1; i < gridRows; i++) {
     for(int j = 0; j < gridCols; j++) {
       theGrid[i][j].setType('e');
       theGrid[i][j].remBlock(); //remove the block
     }
   }
  }

bool Grid::isValidRotate(std::vector<Cell *> newpos){
  for (auto p: newpos){
    if(theGrid[p->getRow()][p->getCol()].getState()){
      return false;
    }
  }
  return true;
}

  
  int Grid::getLevel() { return level; }

  Cell * Grid::getCell(int r, int c) { return &theGrid[r][c]; }

  int Grid::getLevel() { return level; }

  void Grid::levelUp() { ++level; }

  void Grid::levelDown() { --level; }

