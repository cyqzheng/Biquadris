#ifndef __CELL_H__
#define __CELL_H__
#include <iostream>
#include <vector>
#include <memory>
#include "subject.h"
#include "observer.h"
//#include "window.h"

class Block;

class Cell : public Observer, public Subject {
    int r, c;
    char type;
    
    
    // GRAPHICS?
    // int width, height;
    // Xwindow * window;

    // Add other private members if necessary

    public:
    std::shared_ptr<Block> thisblock; // points to a block if isBlock is true
    bool isBlock = false;
    Cell(int r, int c);  // Default constructor

    int getRow() const; // Returns the row of the cell
    int getCol() const; // Returns the column of the cell
    void setRow(int row); // Sets the row of the cell to row
    void setCol(int col); // Sets the column of the cell to col
    char getType() const; // Returns the value of isOn.
    void setType(char t); // Sets the type of the cell to t
    bool getState() const; // returns if the cell is part of a block
    void setBlock(std::shared_ptr<Block> ablock); // attach a block to the cell
    int remBlock(); // remove the block and return int of score to add

    //std::string getName() const override; // returns the coordinates of the cell
    //void setCoords(int r, int c, int w, int h, Xwindow * wind);  // Tells me my row and column number.
    // void draw();
    // void undraw();

    void notify(Cell &whoNotified) override;  // My neighbours will call this,
                                               // to let me know they've been
                                               // switched.
    void notifyObservers() override;
    std::string getName() const override;
};

#endif