#ifndef _JBLOCK_H
#define _JBLOCK_H

#include "block.h"
#include <vector>

class JBlock: public Block{
    int curOrientation; // 0 for initial, 1 for 90* cw rotation, 2 for 180* cw rotation, 3 for 270* cw rotation
    public:
    JBlock(std::vector<Cell> positions, Grid * theGrid);
    char getType();
    void rotateCw();
    void rotateCcw();
    // bool isValidRotate(std::vector<Cell>); already part of grid?
};

#endif
