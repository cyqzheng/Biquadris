#include "starblock.h"

char StarBlock::getType(){
    return '*';
}

StarBlock::StarBlock(std::vector<Cell *> positions, Grid * theGrid, int level): Block(positions, theGrid, level){}