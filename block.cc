#include "block.h"

Block::Block(std::vector<Cell> positions, Grid * theGrid, bool heavy, bool extraHeavy)
: position{positions}, theGrid{theGrid}, heavy{heavy}, extraHeavy{extraHeavy} {}

std::vector<Cell> Block::getCells(){
    return position;
}
void Block::setCells(std::vector<Cell> newcells){
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
    // availability based on cell containing block that is not this one or out of range
    // if not available return with no effect
    for(std::size_t i=0; i<position.size(); ++i){
        position[i] = theGrid->getCell(position[i].getRow()-1, position[i].getCol());
    }
}
bool Block::left(){
    // call a function in cell or grid to check if the cells to the left are available
    // availability based on cell containing block that is not this one
    // if not available return with no effect
    for(std::size_t i=0; i<position.size(); ++i){
        position[i] = theGrid->getCell(position[i].getRow(), position[i].getCol()-1);
    }
}
bool Block::right(){
    // call a function in cell or grid to check if the cells to the right are available
    // availability based on cell containing block that is not this one
    // if not available return with no effect
    for(std::size_t i=0; i<position.size(); ++i){
        position[i] = theGrid->getCell(position[i].getRow(), position[i].getCol()+1);
    }
}
void Block::drop(){
    bool avail = false;
    // call availability function
    while(avail){
        avail = downOne();
    }
} // repeatedly call downOne until not possible
