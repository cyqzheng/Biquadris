#include "tblock.h"
#include "grid.h"
#include "cell.h"

TBlock::TBlock(std::vector<Cell *> positions, Grid * theGrid, int level): Block(positions, theGrid, level){
    curOrientation = 0;
}

char TBlock::getType(){
    return 'T';
}

void TBlock::rotateCw(){
    // create temp vector of new positions
    // check if they are available in other method
    std::vector<Cell *> newpos;

    // hard coded :)
    if(curOrientation==0){
        newpos.push_back(theGrid->getCell(position[0]->getRow()-1, position[0]->getCol()+1));
        newpos.push_back(theGrid->getCell(position[1]->getRow()-0, position[1]->getCol()+0));
        newpos.push_back(theGrid->getCell(position[2]->getRow()+1, position[2]->getCol()-1));
        newpos.push_back(theGrid->getCell(position[3]->getRow()-1, position[3]->getCol()-1));
    }
    else if(curOrientation==1){
        newpos.push_back(theGrid->getCell(position[0]->getRow()+2, position[0]->getCol()+1));
        newpos.push_back(theGrid->getCell(position[1]->getRow()+1, position[1]->getCol()-0));
        newpos.push_back(theGrid->getCell(position[2]->getRow()-0, position[2]->getCol()-1));
        newpos.push_back(theGrid->getCell(position[3]->getRow()-0, position[3]->getCol()+1));
    }
    else if(curOrientation==2){
        newpos.push_back(theGrid->getCell(position[0]->getRow()-0, position[0]->getCol()-2));
        newpos.push_back(theGrid->getCell(position[1]->getRow()-1, position[1]->getCol()-1));
        newpos.push_back(theGrid->getCell(position[2]->getRow()-2, position[2]->getCol()+0));
        newpos.push_back(theGrid->getCell(position[3]->getRow()+0, position[3]->getCol()+0));
    }
    else if(curOrientation==3){
        newpos.push_back(theGrid->getCell(position[0]->getRow()-1, position[0]->getCol()+0));
        newpos.push_back(theGrid->getCell(position[1]->getRow()+0, position[1]->getCol()+1));
        newpos.push_back(theGrid->getCell(position[2]->getRow()+1, position[2]->getCol()+2));
        newpos.push_back(theGrid->getCell(position[3]->getRow()+1, position[3]->getCol()+0));
    }
    bool avail = theGrid->isValidRotate(newpos);

    if(avail){
        position = newpos;
        curOrientation = (curOrientation+1)%4;
    }
}

void TBlock::rotateCcw(){
    for (int i=0; i<3; ++i){
        rotateCw();
    }
}