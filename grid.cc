#include <iostream>
#include "grid.h"
#include "block.h"

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
      theGrid[i][j].isBlock = false;
    }
  }
}


Grid::~Grid() { 
  theGrid.clear(); // clear all elements in the vector
  //delete td; // delete the pointer
}

void Grid::placeBlock(){
  for (auto c : b->position){
    c->setBlock(b);
    if (graphics) window->notify(this, c->getRow(), c->getCol());
  }
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
      //while(isRowFull(i)){
        clearRow(i);
        ++num;
      //}
    }
  }
  if (num!=0) score += (level + num)*(level+num);
  if (score > highscore) highscore = score;
  if (graphics) window->scoreupdate();
  return num;
}

 bool Grid::isRowFull(int row) const {
   if (row >= gridRows) return false;
   std::vector<Cell> rows = theGrid[row];

   for(int i = 0; i < gridCols; i++) {
     if(!rows[i].getState()) return false;
   }
   return true;
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
       else{
         theGrid[i][j].remBlock();  
       }
       if (graphics) window->notify(this, i, j);
     }
   }
   //reset top row
   for (int j=0; j < gridCols; ++j){
     theGrid[0][j].remBlock();
     theGrid[0][j].setType('e');
     if (graphics) window->notify(this, 0, j);
  }
}

  bool Grid::isGameOver() {
    std::vector<Cell> topRow = theGrid[3];
    int counter = 0;
    for(int i = 0; i < gridCols; i++) {
      if(topRow[i].getState()) return true; // top row contains a block
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
   level = 0;
   score = 0;
   if (graphics) window->showWindow();
  }

bool Grid::isValidRotate(std::vector<Cell *> newpos){
  for (auto p: newpos){
    if (p->getRow()>gridRows || p->getCol() > gridCols || p->getRow() < 0 || p->getCol() < 0){
      return false;
    }
    if(theGrid[p->getRow()][p->getCol()].getState()){
      return false;
    }
  }
  return true;
}

int Grid::getRows(){
  return gridRows;
}

int Grid::getCols(){
  return gridCols;
}

  
  Cell * Grid::getCell(int r, int c) { return &theGrid[r][c]; }

  int Grid::getLevel() { return level; }

  void Grid::levelUp() { if (level<4) ++level; }

  void Grid::levelDown() { if (level>0) --level; }

