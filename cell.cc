#include "cell.h"
#include "block.h"
#include <algorithm>

Cell::Cell(int r, int c) : type{'e'}, r{r}, c{c} {
  isBlock = false;
}

int Cell::getRow() const { return r; }

int Cell::getCol() const { return c; }

void Cell::setRow(int row) { r = row; }

void Cell::setCol(int col) { c = col; }

char Cell::getType() const { return type; }

void Cell::setType(char t) { type = t; }

bool Cell::getState() const { return isBlock; }

void Cell::setBlock(std::shared_ptr<Block> ablock) { 
  if (isBlock){ // check if score issues occur here
    remBlock();
  }
  thisblock = ablock; 
  // make block point to cell if it wasn't already
  bool exists = false;
  for (auto b : ablock->position){
    if (b == this) exists = true;
  }
  if (!exists){
    ablock->position.push_back(this);
  }
  isBlock = true;
  type = ablock->getType();
}

int Cell::remBlock() { 
  int addscore = 0;
  if (isBlock){ // if a block used to exists, detach cell from its positions
    thisblock->position.erase(std::remove(thisblock->position.begin(), thisblock->position.end(), this), thisblock->position.end());
    if (thisblock->position.size()==0){
      addscore = (thisblock->level+1)*(thisblock->level+1);
    }
  }
  isBlock = false; 
  return addscore;
}

// std::string Cell::getName() const {
//   std::string res = ""; // get coordinates and return
//   res = '(' + std::to_string(this->r) + ',' + std::to_string(this->c) + ')';
//   return res;
// }

// void Cell::setCoords(int r, int c, int w, int h, Xwindow *wind) { this->r = r; this->c = c; width = w; height = h; window = wind;}

// void Cell::draw() {
//   window->fillRectangle(c*width, r*height, width, height, Xwindow::Black);
// }

// void Cell::undraw() {
//   window->fillRectangle(c*width, r*height, width, height, Xwindow::White);
// }

void Cell::notify(Cell & whoNotified) {
  // toggle the cell
  if(isBlock) {
    isBlock = false;
    //undraw();
  }
  else {
    isBlock = true;
    //draw();
  }
}

void Cell::notifyObservers() {
  // notifies the observers of the specified subscription type
  for(std::size_t i = 0; i < observers.size(); i++) {
      observers[i]->notify(*this);
  }
}

std::string Cell::getName() const {
  std::string res = ""; // get coordinates and return
  res = '(' + std::to_string(this->r) + ',' + std::to_string(this->c) + ')';
  return res;
}
