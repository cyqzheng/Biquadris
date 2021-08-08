#include <iostream>
#include <string>
#include "controller.h"
#include "cell.h"


using std::cin;
using std::getline;

Biquadris::Biquadris(int width, int height) : width{width}, height{height}, g{Grid{width, height}} {}

void Biquadris::run() {
    std::string cmd;
    int x, y;
    int N;
    while (getline(cin,cmd)) {
        if(cmd.compare("left")) {
                // get block in the grid and manipulate it
            g.block.left();                                     //added this in bc there was just nothing here?? ~Crystal
            if (g.getLevel() == 3) g.block.down();              //new and improved (level 3 heavy)
        }
        else if(cmd.compare("right")) { 
            g.block.right(); 
            if (g.getLevel() == 3) g.block.down();              //new and improved (level 3 heavy)
        }
        else if(cmd.compare("down")) { 
            g.block.down(); 
            if (g.getLevel() == 3) g.block.down();              //new and improved (level 3 heavy)
        }
        else if(cmd.compare("clockwise")) { 
            g.block.clockwise();
            if (g.getLevel() == 3) g.block.down();              //new and improved (level 3 heavy)
        }
        else if(cmd.compare("counterclockwise")) { 
            g.block.cclockwise(); 
            if (g.getLevel() == 3) g.block.down();              //new and improved (level 3 heavy)
        }
        else if(cmd.compare("drop")) { g.block.right(); }       //does anyone know why "drop" moves the block right?...
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
    }
}

int Biquadris::getCurScore() { return score; }

int Biquadris::getHighScore() { return hiScore; }

void Biquadris::switchPlayer() { 
    if(player == 1) player = 2;
    else player = 1;
}
