#include <iostream>
#include <string>
#include "controller.h"

using std::cin;
using std::getline;

Biquadris::Biquadris(int width, int height) : width{width}, height{height}, g{Grid{width, height}} {}

void Biquadris::run() {
    std::string cmd;
    int x, y;
    int N;
    int count = 0;                                              //count: number of block placements since last row clear   ~Crystal
    while (getline(cin,cmd)) {
        if(cmd.compare("left")) {
                // get block in the grid and manipulate it
            
            if (g.getLevel() == 3) g.b.downOne();               //new and improved (level 3 heavy)
        }
        else if(cmd.compare("right")) { 
            g.b.right(); 
            if (g.getLevel() == 3) g.b.downOne();               //new and improved (level 3 heavy)
        }
        else if(cmd.compare("down")) { 
            g.b.downOne(); 
            if (g.getLevel() == 3) g.b.downOne();               //new and improved (level 3 heavy)
        }
        else if(cmd.compare("clockwise")) { 
            g.b.rotateCw();
            if (g.getLevel() == 3) g.b.downOne();               //new and improved (level 3 heavy)
        }
        else if(cmd.compare("counterclockwise")) { 
            g.b.rotateCcw(); 
            if (g.getLevel() == 3) g.b.downOne();              //new and improved (level 3 heavy)
        }
        else if(cmd.compare("drop")) { 
            g.b.drop();                                 //does anyone know why "drop" moves the block right?...
            count++;                                            //count goes up per dropped block
            this->switchPlayer();
            char nextBlock = lev.genNext(0);
            if(nextBlock == 'i') {
                IBlock newBlock;
            }
        }
        else if(cmd.compare("levelup")) { g.levelUp(); }
        else if(cmd.compare("leveldown")) { g.levelDown(); }
        else if(cmd.compare("norandom file")) {}
        else if(cmd.compare("random")) {}
        else if(cmd.compare("sequence file")) {}
        else if(cmd.compare("I")) {} // for debugging, changes the block to the specified type
        else if(cmd.compare("J")) {}
        else if(cmd.compare("L")) {}
        else if(cmd.compare("O")) {}
        else if(cmd.compare("S")) {}
        else if(cmd.compare("T")) {}
        else if(cmd.compare("Z")) {}
        else if(cmd.compare("restart")) { 
            g.reset();
        }
        
        if (g.isRowFull()){
            while (g.isRowFull()) g.clearRow();                   //added clearing
            count = 0;
        }
        else if (count % 5 == 0 && count > 0) {
            // drop starblock                                      initializing blocks is nonexistent here so I'll leave this
        }
    }
}

int Biquadris::getCurScore() { return score; }

int Biquadris::getHighScore() { return hiScore; }

void Biquadris::switchPlayer() { 
    if(player == 1) player = 2;
    else player = 1;
}
