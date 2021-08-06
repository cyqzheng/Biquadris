#ifndef __CELL_H__
#define __CELL_H__

class Cell {
    int r, c;
    char type;
    // GRAPHICS?
    // int width, height;
    // Xwindow * window;

    // Add other private members if necessary

    public:
    Cell();  // Default constructor

    int getRow() const; // Returns the row of the cell
    int getCol() const; // Returns the column of the cell
    void setRow(int row); // Sets the row of the cell to row
    void setCol(int col); // Sets the column of the cell to col
    char getType() const; // Returns the value of isOn.
    void setType(char t); // Sets the type of the cell to t

    //std::string getName() const override; // returns the coordinates of the cell
    //void setCoords(int r, int c, int w, int h, Xwindow * wind);  // Tells me my row and column number.
    // void draw();
    // void undraw();

};

#endif