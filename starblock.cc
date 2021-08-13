#include "starblock.h"

StarBlock::StarBlock(std::vector<Cell *> positions, Grid * theGrid, int level): Block(positions, theGrid, level){}

char StarBlock::getType(){
    return '*';
}

void StarBlock::rotateCw(){}

void StarBlock::rotateCcw(){}

