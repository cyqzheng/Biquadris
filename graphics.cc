#include <iostream>
#include <iomanip>
#include <string>

#include "graphics.h"
#include "cell.h"
#include "grid.h"
#include "block.h"

using namespace std;

Graphics::Graphics(int rows, int columns, Grid * g1, Grid * g2) : rows{rows},  cols{columns}, g1{g1}, g2{g2}{
    window = std::make_unique<Xwindow>(rows*w*2+space, cols*w+header+4*w);
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

void Graphics::showWindow(){

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
    window->drawString(0, w+cols*w+header, mynext);
    window->drawString(space+rows*w, w+cols*w+header, mynext);
    

    for (int i  = 0; i < cols; i++){
        for(int j = 0; j < rows; j++){
            bool set = false;
            if (g1->blind && i>=5 && i <=14 && j>=2 && j<=8 ){
                set = true;
                window->fillRectangle(j*w, i*w+header, w, w, Xwindow::Grey);
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
            if (g2->blind && i>5 && i <=14 && j>=2 && j<=8 ){
                set = true;
                window->fillRectangle(j*w+space+rows*w, i*w+header, w, w, Xwindow::Grey);
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
        //cout << endl;
    }

    int k1=0;
    int k2=0;
    for (int j = 0; j < 4; j++){
        if (k1 < 4 && g1->nextb->position[k1]->getRow()==2 && g1->nextb->position[k1]->getCol() == j){ // has row above
            window->fillRectangle(j*w, w+cols*w+w+header, w, w, ctoi(g1->nextb->getType()));
            k1++;
        }
        else{
            window->fillRectangle(j*w, w+cols*w+w+header, w, w, Xwindow::White);
        }
    }
    for (int j = 0; j < 4; j++){
        if (k2 < 4 && g2->nextb->position[k2]->getRow()==2 && g2->nextb->position[k2]->getCol() == j){ // has row above
        window->fillRectangle(j*w+space+rows*w, w+cols*w+w+header, w, w, ctoi(g2->nextb->getType()));
        k2++;
        }
        else{
             window->fillRectangle(j*w+space+rows*w, w+cols*w+w+header, w, w, Xwindow::White);
        }

    }

    for (int j = 0; j < 4; j++){
        if (k1 < 4 && g1->nextb->position[k1]->getRow()==3 && g1->nextb->position[k1]->getCol() == j){ // has row above
            window->fillRectangle(j*w, w+cols*w+w*2+header, w, w, ctoi(g1->nextb->getType()));
            k1++;
        }
        else{
            window->fillRectangle(j*w, w+cols*w+w*2+header, w, w, Xwindow::White);
        }
    }
    for (int j = 0; j < 4; j++){
        if (k2 < 4 && g2->nextb->position[k2]->getRow()==3 && g2->nextb->position[k2]->getCol() == j){ // has row above
            window->fillRectangle(j*w+space+rows*w, w+cols*w+w*2+header, w, w, ctoi(g2->nextb->getType()));            
            k2++;
        }
        else{
            window->fillRectangle(j*w+space+rows*w, w+cols*w+w*2+header, w, w, Xwindow::White);
        }

    }

}

void Graphics::updateBlock(int player, std::vector<Cell *> oldpositions){
    if (player == 1){
        if (oldpositions != g1->b->position){
            for (auto o : oldpositions){
                if (!g1->blind || o->getCol()<2 || o->getCol()>8 || o->getRow()<5 || o->getCol()>14){
                    window->fillRectangle(o->getCol()*w, o->getRow()*w+header, w, w, Xwindow::Black);
                }
                else{
                    window->fillRectangle(o->getCol()*w, o->getRow()*w+header, w, w, Xwindow::Grey);
                }
            }
        }
        for (auto c : g1->b->position){
            if (!g1->blind || c->getCol()<2 || c->getCol()>8 || c->getRow()<5 || c->getCol()>14){
                window->fillRectangle(c->getCol()*w, c->getRow()*w+header, w, w, ctoi(g1->b->getType()));
            }
        }
    }

    else{
        if (oldpositions != g2->b->position){
            for (auto o : oldpositions){
                if (!g2->blind || o->getCol()<2 || o->getCol()>8 || o->getRow()<5 || o->getCol()>14){
                    window->fillRectangle(o->getCol()*w+space+rows*w, o->getRow()*w+header, w, w, Xwindow::Black);
                }
                else{
                    window->fillRectangle(o->getCol()*w+space+rows*w, o->getRow()*w+header, w, w, Xwindow::Grey);
                }
            }
        }
        for (auto c : g2->b->position){
            if (!g2->blind || c->getCol()<2 || c->getCol()>8 || c->getRow()<5 || c->getCol()>14){
                window->fillRectangle(c->getCol()*w+space+rows*w, c->getRow()*w+header, w, w, ctoi(g2->b->getType()));
            }
        }
    }
    
}

void Graphics::updateNextBlock(int player){
    int k1=0;
    int k2=0;
    if (player==1){
        for (int j = 0; j < 4; j++){
            if (k1 < 4 && g1->nextb->position[k1]->getRow()==2 && g1->nextb->position[k1]->getCol() == j){ // has row above
                window->fillRectangle(j*w, w+cols*w+w+header, w, w, ctoi(g1->nextb->getType()));
                k1++;
            }
            else{
                window->fillRectangle(j*w, w+cols*w+w+header, w, w, Xwindow::White);
            }
        }
        for (int j = 0; j < 4; j++){
            if (k1 < 4 && g1->nextb->position[k1]->getRow()==3 && g1->nextb->position[k1]->getCol() == j){ // has row above
                window->fillRectangle(j*w, w+cols*w+w*2+header, w, w, ctoi(g1->nextb->getType()));
                k1++;
            }
            else{
                window->fillRectangle(j*w, w+cols*w+w*2+header, w, w, Xwindow::White);
            }
        }
    }
    else {
        for (int j = 0; j < 4; j++){
            if (k2 < 4 && g2->nextb->position[k2]->getRow()==2 && g2->nextb->position[k2]->getCol() == j){ // has row above
            window->fillRectangle(j*w+space+rows*w, w+cols*w+w+header, w, w, ctoi(g2->nextb->getType()));
            k2++;
            }
            else{
                window->fillRectangle(j*w+space+rows*w, w+cols*w+w+header, w, w, Xwindow::White);
            }
        }
        for (int j = 0; j < 4; j++){
            if (k2 < 4 && g2->nextb->position[k2]->getRow()==3 && g2->nextb->position[k2]->getCol() == j){ // has row above
                window->fillRectangle(j*w+space+rows*w, w+cols*w+w*2+header, w, w, ctoi(g2->nextb->getType()));            
                k2++;
            }
            else{
                window->fillRectangle(j*w+space+rows*w, w+cols*w+w*2+header, w, w, Xwindow::White);
            }

        }
    }
} 

// when cells change
void Graphics::notify(Grid * mygrid, int r, int c){
    if (mygrid->player==2){
        if (!g2->blind || mygrid->theGrid[r][c].getCol()<2 || mygrid->theGrid[r][c].getCol()>8 || mygrid->theGrid[r][c].getRow()<5 || mygrid->theGrid[r][c].getCol()>14){
            if (mygrid->theGrid[r][c].getState()){
                window->fillRectangle(c*w+space+rows*w, r*w+header, w, w, ctoi(g2->theGrid[r][c].getType()));
            }
            else{
                window->fillRectangle(c*w+space+rows*w, r*w+header, w, w, Xwindow::Black);
            }
        }
        else{
            window->fillRectangle(c*w+space+rows*w, r*w+header, w, w, Xwindow::Grey);
        }
    }
    if (mygrid->player==1){
        if (!(g1->blind) || mygrid->theGrid[r][c].getCol()<2 || mygrid->theGrid[r][c].getCol()>8 || mygrid->theGrid[r][c].getRow()<5 || mygrid->theGrid[r][c].getCol()>14){
            if (mygrid->theGrid[r][c].getState()){
                window->fillRectangle(c*w, r*w+header, w, w, ctoi(g2->theGrid[r][c].getType()));
            }
            else{
                window->fillRectangle(c*w, r*w+header, w, w, Xwindow::Black);
            }
        }
        else{
            window->fillRectangle(c*w, r*w+header, w, w, Xwindow::Grey);
        }
    }
}

void Graphics::levelupdate(){
    std::string p1level = "Level: " + std::to_string(g1->getLevel());
    std::string p2level = "Level: " + std::to_string(g2->getLevel());
    window->fillRectangle(0, 0, w*rows*2+space, w, Xwindow::White);
    window->drawString(space+rows*w, w, p2level);
    window->drawString(0, w, p1level);
}

void Graphics::scoreupdate(){
    std::string p1high  = "   Hi: " + std::to_string(g1->highscore);
    std::string p2high  = "   Hi: " + std::to_string(g2->highscore);
    std::string p1score = "Score: " + std::to_string(g1->score);
    std::string p2score = "Score: " + std::to_string(g2->score);
    window->fillRectangle(0, w, w*rows*2+space, w*2, Xwindow::White);
    window->drawString(0, w*2, p1high);
    window->drawString(0, w*3, p1score);
    window->drawString(space+rows*w, w*2, p2high);
    window->drawString(space+rows*w, w*3, p2score);
}

