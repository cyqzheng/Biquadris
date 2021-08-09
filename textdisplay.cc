#include <iostream>
#include "textdisplay.h"
#include "subject.h"
#include "observer.h"
#include "cell.h"

using namespace std;

TextDisplay::TextDisplay(int n) : gridSize{n} {
  // initialize the displayed grid with off 
  for(int i = 0; i < n; ++i) {
    theDisplay.emplace_back(vector< char >());
    for(int j = 0; j < n; ++j) {
      theDisplay[i].emplace_back('.');
    }
  }
}

void TextDisplay::notify(Cell &whoNotified) {
  // toggle the value of the cell
  int cellR = whoNotified.getRow();
  int cellC = whoNotified.getCol();
  if(theDisplay[cellR][cellC] == '.') theDisplay[cellR][cellC] = 'X';
  else theDisplay[cellR][cellC] = '.';
}

TextDisplay::~TextDisplay() {
  // clear the vector
  theDisplay.clear();
}

std::string TextDisplay::getName() const {
  return "TD";
}

ostream &operator<<(ostream &out, const TextDisplay &td) {
  // add each cell to the ostream, row by row
  for(int i = 0; i < td.gridSize; i++) {
    for(int j = 0; j < td.gridSize; j++) {
      out << td.theDisplay[i][j];
    }
    out << endl;
  }
  return out;
}
