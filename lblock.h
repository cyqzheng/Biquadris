#ifndef _LBLOCK_H
#define _LBLOCK_H

#include "block.h"
#include <vector>

class LBlock: public Block{
    int curOrientation; // 0 for initial, 1 for 90* cw rotation, 2 for 180* cw rotation, 3 for 270* cw rotation
    public:
    LBlock(std::vector<Cell *> positions, Grid * theGrid, int level);
    char getType();
    void rotateCw();
    void rotateCcw();
    // bool isValidRotate(std::vector<Cell>); already part of grid?
};

#endif
