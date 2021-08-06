#include "cell.h"

Cell::Cell() : type{'e'} {}

int Cell::getRow() const { return r; }

int Cell::getCol() const { return c; }

void Cell::setRow(int row) { r = row; }

void Cell::setCol(int col) { c = col; }

char Cell::getType() const { return type; }

void Cell::setType(char t) { type = t; }

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
