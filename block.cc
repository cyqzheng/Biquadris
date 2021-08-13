#include "block.h"
#include "grid.h"
#include "cell.h"

#include <iostream>

Block::Block(std::vector<Cell *> positions, Grid * theGrid, int level, bool heavy, bool extraHeavy)
: position{positions}, theGrid{theGrid}, level{level}, heavy{heavy}, extraHeavy{extraHeavy} {
    if (level>=3){
        heavy = true;
    }
}

Block::~Block(){}

std::vector<Cell *> Block::getCells(){
    return position;
}
void Block::setCells(std::vector<Cell *> newcells){
    position = newcells;
}

bool Block::getHeavy(){
    return heavy;
}

void Block::setHeavy(){
    heavy = true;
}

bool Block::getExtraHeavy(){
    return extraHeavy;
}
void Block::setExtraHeavy(){
    extraHeavy = true;
}

bool Block::downOne(){
    // call a function in cell or grid to check if the cells below are available
    std::vector<Cell *> nextp;
    for(std::size_t i=0; i<position.size(); ++i){
        if (position[i]->getRow()+1 >= theGrid->getRows()){
            return false;
        }
        nextp.push_back(theGrid->getCell(position[i]->getRow()+1, position[i]->getCol()));
    }
    if(theGrid->isValidRotate(nextp)==false){
        return false;
    }
    // availability based on cell containing block that is not this one or out of range
    // if not available return with no effect
    position = nextp;
    return true;
}
bool Block::left(){
    // call a function in cell or grid to check if the cells to the left are available
    std::vector<Cell *> nextp;
    for(std::size_t i=0; i<position.size(); ++i){
        if (position[i]->getCol()-1 < 0){
            return false;
        }
        nextp.push_back(theGrid->getCell(position[i]->getRow(), position[i]->getCol()-1));
    }
    if(theGrid->isValidRotate(nextp)==false){
        return false;
    }
    // availability based on cell containing block that is not this one
    // if not available return with no effect
    position = nextp;
    return true;

}
bool Block::right(){
    // call a function in cell or grid to check if the cells to the right are available
    std::vector<Cell *> nextp;
    for(std::size_t i=0; i<position.size(); ++i){
        if (position[i]->getCol()+1 >= theGrid->getCols()){
            return false;
        }
        nextp.push_back(theGrid->getCell(position[i]->getRow(), position[i]->getCol()+1));
    }
    if(theGrid->isValidRotate(nextp)==false){
        return false;
    }
    // availability based on cell containing block that is not this one
    // if not available return with no effect
    position = nextp;
    return true;
}
void Block::drop(){
    bool avail = true;
    // call availability function
    while(avail){
        avail = downOne();
    }
} // repeatedly call downOne until not possible
