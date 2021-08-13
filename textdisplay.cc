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
  cout << endl;
  cout << "Level:" << setfill(' ') << setw(5) << g1->getLevel();
  cout << "     " ;
  cout << "Level:" << setfill(' ') << setw(5) << g2->getLevel() << endl;
  cout << "   Hi:" << setfill(' ') << setw(5) << g1->highscore;
  cout << "     " ;
  cout << "   Hi:" << setfill(' ') << setw(5) << g2->highscore << endl;
  cout << "Score:" << setfill(' ') << setw(5) << g1->score;
  cout << "     " ;
  cout << "Score:" << setfill(' ') << setw(5) << g2->score << endl;
     
    cout <<"-----------     -----------" <<endl;
    for (int i  = 0; i < cols; i++){
        for(int j = 0; j < rows; j++){
          bool set = false;
          if (g1->blind && i>=2 && i <=11 && j>=2 && j<=8 ){
            set = true;
            cout << '?';
          }
          for (auto c : g1->b->position){
            if (c->getRow()==i && c->getCol()==j && !set){
              cout << g1->b->getType();
              set = true;
            }
          }
          if (g1->theGrid[i][j].getState() && !set) 
            cout << g1->theGrid[i][j].getType();
          else if (!set) cout << ' ';
        }
        cout << "     " ;
        for(int j = 0; j < rows; j++){
          bool set = false;
          if (g2->blind && i>=2 && i <=11 && j>=2 && j<=8 ){
            set = true;
            cout << '?';
          }
          for (auto c : g2->b->position){
            if (c->getRow()==i && c->getCol()==j && !set){
              cout << g2->b->getType();
              set = true;
            }
          }
          if (g2->theGrid[i][j].getState() && !set) 
            cout << g2->theGrid[i][j].getType();
          else if (!set) cout << ' ';
        }
        cout << endl;
    }
    cout <<"-----------     -----------" <<endl;
    cout <<"Next:           Next:      " << endl;

    int k1=0;
    int k2=0;
    for (int j = 0; j < 4; j++){
        if (k1 < 4 && g1->nextb->position[k1]->getRow()==2 && g1->nextb->position[k1]->getCol() == j){ // has row above
          cout << g1->nextb->getType();
          k1++;
        }
        else{
          cout << ' ';
        }
    }
    cout << "            "; // 12 spaces
    for (int j = 0; j < 4; j++){
        if (k2 < 4 && g2->nextb->position[k2]->getRow()==2 && g2->nextb->position[k2]->getCol() == j){ // has row above
          cout << g2->nextb->getType();
          k2++;
        }
        else{
          cout << ' ';
        }
    }
    cout << endl;

    for (int j = 0; j < 4; j++){
        if (k1 < 4 && g1->nextb->position[k1]->getRow()==3 && g1->nextb->position[k1]->getCol() == j){ // has row above
          cout << g1->nextb->getType();
          k1++;
        }
        else{
          cout << ' ';
        }
    }
    cout << "            "; // 12 spaces
    for (int j = 0; j < 4; j++){
        if (k2 < 4 && g2->nextb->position[k2]->getRow()==3 && g2->nextb->position[k2]->getCol() == j){ // has row above
          cout << g2->nextb->getType();
          k2++;
        }
        else{
          cout << ' ';
        }
    }
    cout << endl;

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


