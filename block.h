#ifndef _BLOCK_H
#define _BLOCK_H

#include <vector>
#include "cell.h" 
#include "grid.h"


// virtual block class
class Block{
    protected:
    // vector of cells or pointer to cells?
    std::vector<Cell> position; 
    Grid * theGrid;
    bool heavy;
    bool extraHeavy;

    public:
    int r, c;
    char getType();
    virtual void rotateCw();
    virtual void rotateCcw();
    // initial vector of cells must be in top to bottom, left to right order
    // I can create a method to ensure this?
    Block(std::vector<Cell> positions, Grid * theGrid, bool heavy = false, bool extraHeavy = false);
    virtual ~Block();

    std::vector<Cell> getCells();
    void setCells(std::vector<Cell> newcells);

    bool getHeavy();
    void setHeavy();
    bool getExtraHeavy();
    void setExtraHeavy();

    bool downOne();
    bool left();
    bool right();
    void drop(); // repeatedly call downOne until not possible

};

#endif
