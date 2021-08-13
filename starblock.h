#ifndef _STARBLOCK_H
#define _STARBLOCK_H

#include "block.h"

class StarBlock: public Block{

    public:
    StarBlock(std::vector<Cell *> positions, Grid * theGrid, int level);
    char getType();
    void rotateCw() override;
    void rotateCcw() override;
};

#endif
