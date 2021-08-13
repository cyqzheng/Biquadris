#ifndef _BLOCK_H
#define _BLOCK_H

#include <vector>

class Grid;
class Cell;

// virtual block class
class Block{
    protected:
    // vector of cells or pointer to cells?
    
    Grid * theGrid;
    bool heavy;
    bool extraHeavy;

    public:

    int level;
    std::vector<Cell *> position; 
    char getType();
    virtual void rotateCw() = 0;
    virtual void rotateCcw() = 0;
    // initial vector of cells must be in top to bottom, left to right order
    // I can create a method to ensure this?
    Block(std::vector<Cell *> positions, Grid * theGrid, int level, bool heavy = false, bool extraHeavy = false);
    ~Block();

    std::vector<Cell *> getCells();
    void setCells(std::vector<Cell *> newcells);

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
