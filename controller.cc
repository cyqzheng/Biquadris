#include <iostream>
#include <string>
#include "controller.h"

using std::cin;
using std::getline;

//Biquadris::Biquadris(){}
Biquadris::Biquadris(int width, int height) : width{width}, height{height} {}

void Biquadris::run() {
    std::string cmd;
    int x, y;
    int N;
    int count1 = 0;                                              //count1: number of block placements since last row clear for p1
    int count2 = 0;

    while (getline(cin,cmd)) {
        if(!cmd.compare("left")) {
            // get block in the grid and manipulate it
            if(player==1){
                g1.b->left();
                if (g1.getLevel() == 3) g1.b->downOne();               //new and improved (level 3 heavy)
            }
            if(player==2){
                g2.b->left();
                if (g2.getLevel() == 3) g2.b->downOne();               //new and improved (level 3 heavy)
            }
            
        }
        else if(!cmd.compare("right")) { 
            
            if(player==1){
                g1.b->right();
                if (g1.getLevel() == 3) g1.b->downOne();               //new and improved (level 3 heavy)
            }
            if(player==2){
                g2.b->right();
                if (g2.getLevel() == 3) g2.b->downOne();               //new and improved (level 3 heavy)
            }
        }
        else if(!cmd.compare("down")) { 
            if(player==1){
                g1.b->downOne();
                if (g1.getLevel() == 3) g1.b->downOne();               //new and improved (level 3 heavy)
            }
            if(player==2){
                g2.b->downOne();
                if (g2.getLevel() == 3) g2.b->downOne();               //new and improved (level 3 heavy)
            }
        }
        else if(!cmd.compare("clockwise")) { 

            if(player==1){
                g1.b->rotateCw();
                if (g1.getLevel() == 3) g1.b->downOne();               //new and improved (level 3 heavy)
            }
            if(player==2){
                g2.b->rotateCw();
                if (g2.getLevel() == 3) g2.b->downOne();               //new and improved (level 3 heavy)
            }
        }
        else if(!cmd.compare("counterclockwise")) { 
            if(player==1){
                g1.b->rotateCcw();
                if (g1.getLevel() == 3) g1.b->downOne();               //new and improved (level 3 heavy)
            }
            if(player==2){
                g2.b->rotateCcw();
                if (g2.getLevel() == 3) g2.b->downOne();               //new and improved (level 3 heavy)
            }
        }
        else if(!cmd.compare("drop")) { 
            if(player==1){
                g1.b->drop();
                count1++;
            }
            if(player==2){
                g2.b->drop();
                count2++;
            }
            //count goes up per dropped block
            
            char nextBlock = lev.genNext(player);
            if (player==1){
                g1.nextb = genNext(nextBlock);
            }
            if (player==2){
                g2.nextb = genNext(nextBlock);
            }
            
            this->switchPlayer();
        }
        else if(!cmd.compare("levelup")) { 
            if (player==1){
                g1.levelUp();
            }
            if (player==2){
                g2.levelUp();
            }
        }
        else if(!cmd.compare("leveldown")) { 
            if (player==1){
                g1.levelDown();
            }
            if (player==2){
                g2.levelDown();
            }
        }
        else if(!cmd.compare("norandom file")) {}
        else if(!cmd.compare("random")) {}
        else if(!cmd.compare("sequence file")) {}
        else if(!cmd.compare("I")) {} // for debugging, changes the block to the specified type
        else if(!cmd.compare("J")) {}
        else if(!cmd.compare("L")) {}
        else if(!cmd.compare("O")) {}
        else if(!cmd.compare("S")) {}
        else if(!cmd.compare("T")) {}
        else if(!cmd.compare("Z")) {}
        else if(!cmd.compare("restart")) { 
            if (player==1){
                g1.reset();
            }
            if (player==2){
                g2.reset();
            }
        }

        // note, when removing rows, this also automatically updates the score
        if (player==1){
            int num = g1.remFullRows();
            if (num==0){
                count1 = 0;
            }
            else if (count1 % 5 == 0 && count1 > 0) {
                // drop starblock                                      initializing blocks is nonexistent here so I'll leave this
                // We do this later lol
            }
        }
        
    }
}

std::shared_ptr<Block> Biquadris::genNext(char nextBlock){
    std::vector<Cell *> positions; // cells in grid that will contain block
    std::shared_ptr<Block> newBlock;
    if(nextBlock == 'i') {
        if (player==1){
            positions.push_back(g1.getCell(3,0));  //rows 0,1,2 are the extra rows
            positions.push_back(g1.getCell(3,1));
            positions.push_back(g1.getCell(3,2));
            positions.push_back(g1.getCell(3,3));
            newBlock = std::make_shared<IBlock>(positions, &g1, g1.getLevel());
        }
        else if (player==2){
            positions.push_back(g2.getCell(3,0));  //rows 0,1,2 are the extra rows
            positions.push_back(g2.getCell(3,1));
            positions.push_back(g2.getCell(3,2));
            positions.push_back(g2.getCell(3,3));
            newBlock = std::make_shared<IBlock>(positions, &g2, g2.getLevel()); // check these
        }   
    }
    else if(nextBlock == 'j') {
        if (player==1){
            positions.push_back(g1.getCell(2,0));  
            positions.push_back(g1.getCell(3,0));
            positions.push_back(g1.getCell(3,1));
            positions.push_back(g1.getCell(3,2));
            newBlock = std::make_shared<JBlock>(positions, &g1, g1.getLevel());
        }
        else if (player==2){
            positions.push_back(g2.getCell(2,0));  //rows 0,1,2 are the extra rows
            positions.push_back(g2.getCell(3,0));
            positions.push_back(g2.getCell(3,1));
            positions.push_back(g2.getCell(3,2));
            newBlock = std::make_shared<JBlock>(positions, &g2, g2.getLevel()); // check these
        }   
    }
    else if(nextBlock == 'l') {
        if (player==1){
            positions.push_back(g1.getCell(2,2));  
            positions.push_back(g1.getCell(3,0));
            positions.push_back(g1.getCell(3,1));
            positions.push_back(g1.getCell(3,2));
            newBlock = std::make_shared<LBlock>(positions, &g1, g1.getLevel());
        }
        else if (player==2){
            positions.push_back(g2.getCell(2,2));  //rows 0,1,2 are the extra rows
            positions.push_back(g2.getCell(3,0));
            positions.push_back(g2.getCell(3,1));
            positions.push_back(g2.getCell(3,2));
            newBlock = std::make_shared<LBlock>(positions, &g2, g2.getLevel()); // check these
        }
    }
    else if(nextBlock == 'o') {
        if (player==1){
            positions.push_back(g1.getCell(2,0));  
            positions.push_back(g1.getCell(2,1));
            positions.push_back(g1.getCell(3,0));
            positions.push_back(g1.getCell(3,1));
            newBlock = std::make_shared<OBlock>(positions, &g1, g1.getLevel());
        }
        else if (player==2){
            positions.push_back(g2.getCell(2,0));  //rows 0,1,2 are the extra rows
            positions.push_back(g2.getCell(2,1));
            positions.push_back(g2.getCell(3,0));
            positions.push_back(g2.getCell(3,1));
            newBlock = std::make_shared<OBlock>(positions, &g2, g2.getLevel()); // check these
        }
    }
    else if(nextBlock == 's') {
        if (player==1){
            positions.push_back(g1.getCell(2,1));  
            positions.push_back(g1.getCell(2,2));
            positions.push_back(g1.getCell(3,0));
            positions.push_back(g1.getCell(3,1));
            newBlock = std::make_shared<SBlock>(positions, &g1, g1.getLevel());
        }
        else if (player==2){
            positions.push_back(g2.getCell(2,1));  //rows 0,1,2 are the extra rows
            positions.push_back(g2.getCell(2,2));
            positions.push_back(g2.getCell(3,0));
            positions.push_back(g2.getCell(3,1));
            newBlock = std::make_shared<SBlock>(positions, &g2, g2.getLevel()); // check these
        }
    }
    else if(nextBlock == 't') {
        if (player==1){
            positions.push_back(g1.getCell(2,0));  
            positions.push_back(g1.getCell(2,1));
            positions.push_back(g1.getCell(2,2));
            positions.push_back(g1.getCell(3,1));
            newBlock = std::make_shared<TBlock>(positions, &g1, g1.getLevel());
        }
        else if (player==2){
            positions.push_back(g2.getCell(2,0));  //rows 0,1,2 are the extra rows
            positions.push_back(g2.getCell(2,1));
            positions.push_back(g2.getCell(2,2));
            positions.push_back(g2.getCell(3,1));
            newBlock = std::make_shared<TBlock>(positions, &g2, g2.getLevel()); // check these
        }
    }
    else if(nextBlock == 'z') {
        if (player==1){
            positions.push_back(g1.getCell(2,0));  
            positions.push_back(g1.getCell(2,1));
            positions.push_back(g1.getCell(3,1));
            positions.push_back(g1.getCell(3,2));
            newBlock = std::make_shared<ZBlock>(positions, &g1, g1.getLevel());
        }
        else if (player==2){
            positions.push_back(g2.getCell(2,0));  //rows 0,1,2 are the extra rows
            positions.push_back(g2.getCell(2,1));
            positions.push_back(g2.getCell(3,1));
            positions.push_back(g2.getCell(3,2));
            newBlock = std::make_shared<ZBlock>(positions, &g2, g2.getLevel()); // check these
        }
    }
    return newBlock;
}

int Biquadris::getCurScore() { return score; }

int Biquadris::getHighScore() { return hiScore; }

void Biquadris::switchPlayer() { 
    if(player == 1) player = 2;
    else player = 1;
}
