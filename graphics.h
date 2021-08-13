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

 public:
    std::unique_ptr<Xwindow> window;
    Graphics(int rows, int columns);
    int totalheight();
    int totalwidth();
    void showWindow(Grid * g1, Grid * g2);

    ~Graphics();

};

#endif


