#ifndef _STARBLOCK_H
#define _STARBLOCK_H

#include "block.h"

class StarBlock: public Block{
    public:
    StarBlock(std::vector<Cell> positions, Grid * theGrid);
    char getType() override;
};

#endif
