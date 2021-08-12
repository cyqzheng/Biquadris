#include "oblock.h"

OBlock::OBlock(std::vector<Cell *> positions, Grid * theGrid, int level): Block(positions, theGrid, level){}

char OBlock::getType(){
    return 'O';
}

void OBlock::rotateCw(){
    // create temp vector of new positions
    // check if they are available in other method
    
    //OBlock rotation does nothing
}

void OBlock::rotateCcw(){
    for (int i=0; i<3; ++i){
        rotateCw();
    }
}