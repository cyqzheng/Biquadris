#ifndef _TBLOCK_H
#define _TBLOCK_H

#include "block.h"
#include <vector>

class TBlock: public Block{
    int curOrientation; // 0 for initial, 1 for 90* cw rotation, 2 for 180* cw rotation, 3 for 270* cw rotation
    public:
    TBlock(std::vector<Cell> positions, Grid * theGrid);
    char getType();
    void rotateCw();
    void rotateCcw();
    // bool isValidRotate(std::vector<Cell>); already part of grid?
};

#endif
