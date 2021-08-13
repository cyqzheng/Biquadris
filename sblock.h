#ifndef _SBLOCK_H
#define _SBLOCK_H

#include "block.h"
#include <vector>

class SBlock: public Block{
    int curOrientation; // 0 for initial, 1 for 90* cw rotation, 2 for 180* cw rotation, 3 for 270* cw rotation
    public:
    SBlock(std::vector<Cell *> positions, Grid * theGrid, int level);
    char getType();
    void rotateCw() override;
    void rotateCcw() override;
    // bool isValidRotate(std::vector<Cell>); already part of grid?
};

#endif
