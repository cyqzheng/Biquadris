#include <iostream>
#include <iomanip>
#include <string>

#include "graphics.h"
#include "cell.h"
#include "grid.h"
#include "block.h"

using namespace std;

Graphics::Graphics(int rows, int columns) : rows{rows},  cols{columns}{
    window = std::make_unique<Xwindow>(cols*w*2+space, rows*w+header+4*w);
}

Graphics::~Graphics(){}

int Graphics::totalheight(){
    return cols*w+header;
}
int Graphics::totalwidth(){
    return rows*w+header;
}

int ctoi (char c){
    if (c=='i' || c=='I'){
        return 3;
    }
    else if(c=='j' || c=='J'){
        return 4;
    }
    else if(c=='l' || c=='L'){
        return 5;
    }
    else if(c=='o' || c=='O'){
        return 6;
    }
    else if(c=='s' || c=='S'){
        return 7;
    }
    else if(c=='z' || c=='Z'){
        return 8;
    }
    else if(c=='t' || c=='T'){
        return 8;
    }
    else if(c=='*'){
        return 2;
    }
    else{
        return 0;
    }
}

void Graphics::showWindow(Grid * g1, Grid * g2){

    std::string p1level = "Level: " + std::to_string(g1->getLevel());
    std::string p2level = "Level: " + std::to_string(g2->getLevel());
    std::string p1high  = "   Hi: " + std::to_string(g1->highscore);
    std::string p2high  = "   Hi: " + std::to_string(g2->highscore);
    std::string p1score = "Score: " + std::to_string(g1->score);
    std::string p2score = "Score: " + std::to_string(g2->score);
    std::string mynext  = " Next: ";

    window->drawString(0, w, p1level);
    window->drawString(space+rows*w, w, p2level);
    window->drawString(0, w*2, p1high);
    window->drawString(space+rows*w, w*2, p2high);
    window->drawString(0, w*3, p1score);
    window->drawString(space+rows*w, w*3, p2score);
    window->drawString(0, w+cols*w, mynext);
    window->drawString(space+rows*w, w+cols*w, mynext);
    

    for (int i  = 0; i < cols; i++){
        for(int j = 0; j < rows; j++){
            bool set = false;
            if (g1->blind && i>=2 && i <=11 && j>=2 && j<=8 ){
                set = true;
                window->fillRectangle(j*w, i*w+header, w, w, Xwindow::Black);
            }
            for (auto c : g1->b->position){
                if (c->getRow()==i && c->getCol()==j && !set){
                    window->fillRectangle(j*w, i*w+header, w, w, ctoi(g1->b->getType()));
                    set = true;
                }
            }
            if (g1->theGrid[i][j].getState() && !set) 
                window->fillRectangle(j*w, i*w+header, w, w, ctoi(g1->theGrid[i][j].getType()));
            else if (!set){
                window->fillRectangle(j*w, i*w+header, w, w, Xwindow::Black);
            }
        }

        for(int j = 0; j < rows; j++){
            bool set = false;
            if (g2->blind && i>=2 && i <=11 && j>=2 && j<=8 ){
                set = true;
                window->fillRectangle(j*w+space+rows*w, i*w+header, w, w, Xwindow::Black);
            }
            for (auto c : g2->b->position){
                if (c->getRow()==i && c->getCol()==j && !set){
                    window->fillRectangle(j*w+space+rows*w, i*w+header, w, w, ctoi(g2->b->getType()));
                    set = true;
                }
            }
            if (g2->theGrid[i][j].getState() && !set)
                window->fillRectangle(j*w+space+rows*w, i*w+header, w, w, ctoi(g2->theGrid[i][j].getType())); 

            else if (!set){
                window->fillRectangle(j*w+space+rows*w, i*w+header, w, w, Xwindow::Black);
            }
        }
        cout << endl;
    }

    int k1=0;
    int k2=0;
    for (int j = 0; j < 4; j++){
        if (k1 < 4 && g1->nextb->position[k1]->getRow()==2 && g1->nextb->position[k1]->getCol() == j){ // has row above
            window->fillRectangle(j*w, w+cols*w+w, w, w, ctoi(g1->nextb->getType()));
            k1++;
        }
    }
    for (int j = 0; j < 4; j++){
        if (k2 < 4 && g2->nextb->position[k2]->getRow()==2 && g2->nextb->position[k2]->getCol() == j){ // has row above
        window->fillRectangle(j*w+space+rows*w, w+cols*w+w, w, w, ctoi(g2->nextb->getType()));
        k2++;
        }

    }

    for (int j = 0; j < 4; j++){
        if (k1 < 4 && g1->nextb->position[k1]->getRow()==3 && g1->nextb->position[k1]->getCol() == j){ // has row above
            window->fillRectangle(j*w, w+cols*w+w*2, w, w, ctoi(g1->nextb->getType()));
            k1++;
        }
    }
    for (int j = 0; j < 4; j++){
        if (k2 < 4 && g2->nextb->position[k2]->getRow()==3 && g2->nextb->position[k2]->getCol() == j){ // has row above
            window->fillRectangle(j*w+space+rows*w, w+cols*w+w*2, w, w, ctoi(g2->nextb->getType()));            
            k2++;
        }

    }

}



