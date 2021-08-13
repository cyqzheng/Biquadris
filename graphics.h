#ifndef __GRAPHICS_H__
#define __GRAPHICS_H__
#include <iostream>
#include <vector>
#include <memory>
#include "window.h"

class Grid;
class Cell;

class Graphics{
    const int rows;
    const int cols;
    const int w = 20; // side length of square tile
    const int header = w*5; // add to height of board
    const int space = 2*w;
    Grid * g1;
    Grid * g2;

 public:
    std::unique_ptr<Xwindow> window;
    Graphics(int rows, int columns, Grid * g1, Grid * g2);
    int totalheight();
    int totalwidth();
    void showWindow();
    void updateNextBlock(int player);
    void updateBlock (int player, std::vector<Cell *> oldpositions);
    void notify(Grid * thegrid, int r, int c);
    void levelupdate();
    void scoreupdate();

    ~Graphics();

};

#endif


