#ifndef _OBLOCK_H
#define _OBLOCK_H

#include "block.h"
#include <vector>

class OBlock: public Block{
    public:
    OBlock(std::vector<Cell *> positions, Grid * theGrid, int level);
    char getType();
    void rotateCw() override;
    void rotateCcw() override;
    // bool isValidRotate(std::vector<Cell>); already part of grid?
};

#endif
