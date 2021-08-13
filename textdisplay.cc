#include <iostream>
#include <iomanip>
#include "textdisplay.h"
#include "subject.h"
#include "observer.h"
#include "cell.h"
#include "grid.h"
#include "block.h"
using namespace std;

TextDisplay::TextDisplay(int rows, int columns) : rows{rows},  cols{columns}{
  // initialize the displayed grid with empty spaces
  for(int i = 0; i < rows; ++i) {
    play1.emplace_back(vector< char >());
    play2.emplace_back(vector< char >());
    for(int j = 0; j < cols; ++j) {
      play1[i].emplace_back(' ');
      play2[i].emplace_back(' ');
    }
  }
}

TextDisplay::~TextDisplay(){}

void TextDisplay::showText(Grid * g1, Grid * g2){
  cout << "Level:" << setfill(' ') << setw(5) << g1->getLevel();
  cout << "     " ;
  cout << "Level:" << setfill(' ') << setw(5) << g2->getLevel() << endl;
  cout << "Score:" << setfill(' ') << setw(5) << g1->score;
  cout << "     " ;
  cout << "Score:" << setfill(' ') << setw(5) << g2->score << endl;
     
    cout <<"-----------     -----------" <<endl;
    for (int i  = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
                cout << g1->theGrid[i][j].getType();
        }
        cout << "     " ;
        for(int j = 0; j < cols; j++){
                cout << g2->theGrid[i][j].getType();
        }
        cout << endl;
    }
    cout <<"-----------     -----------" <<endl;
    cout <<"Next:           Next:      " << endl;
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 4; j++){
            if (g1->nextb->position[j]->getRow()==i+2){ // has row above
              cout << g1->nextb->position[j]->getType();
            }
            else{
              cout << ' ';
            }
        }
        cout << "            "; // 12 spaces
        for (int j = 0; j < 4; j++){
            if (g2->nextb->position[j]->getRow()==i+2){ // has row above
              cout << g2->nextb->position[j]->getType();
            }
            else{
              cout << ' ';
            }
        }
        cout << endl;
    }
}


// everything underneath is if I feel like doing observer patter
// notify one cell at a time
/*void TextDisplay::notify(Cell &whoNotified) {
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
}*/


