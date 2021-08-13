#include <iostream>
#include <string>
#include "controller.h"

using std::cin;
using std::getline;

//Biquadris::Biquadris(){}
Biquadris::Biquadris(int width, int height) : width{width}, height{height} {
    td = std::make_shared<TextDisplay>(width, height);
    g1.player = 1;
    g2.player = 2;
    lev1 = std::make_shared<LevelZero>();
    lev2 = std::make_shared<LevelZero>();
}

void Biquadris::run() {
    std::string cmd;
    int count1 = 0;                                              //count1: number of block placements since last row clear for p1
    int count2 = 0;
    bool extrah1 = false;
    bool extrah2 = false;

    
    player = 1;
    g1.b = genNext(lev1->genNext(player));
    g1.nextb = genNext(lev1->genNext(player));

    player = 2;
    g2.b = genNext(lev2->genNext(player));
    g2.nextb = genNext(lev2->genNext(player));

    player = 1;
    td->showText(&g1, &g2);

    while (getline(cin,cmd)) {
        if(!cmd.compare("left")) {
            // get block in the grid and manipulate it
            if(player==1){
                g1.b->left();
                if (g1.getLevel() >= 3) g1.b->downOne();               //new and improved (level 3 heavy)
                if (extrah1){
                    g1.b->downOne();
                    g1.b->downOne();
                }
            }
            if(player==2){
                g2.b->left();
                if (g2.getLevel() >= 3) g2.b->downOne();               //new and improved (level 3 heavy)
                if (extrah2){
                    g2.b->downOne();
                    g2.b->downOne();
                }
            }
            
        }
        else if(!cmd.compare("right")) { 
            
            if(player==1){
                g1.b->right();
                if (g1.getLevel() >= 3) g1.b->downOne();               //new and improved (level 3 heavy)
                if (extrah1){
                    g1.b->downOne();
                    g1.b->downOne();
                }
            }
            if(player==2){
                g2.b->right();
                if (g2.getLevel() >= 3) g2.b->downOne();               //new and improved (level 3 heavy)
                if (extrah2){
                    g2.b->downOne();
                    g2.b->downOne();
                }
            }
        }
        else if(!cmd.compare("down")) { 
            if(player==1){
                g1.b->downOne();
                if (g1.getLevel() >= 3) g1.b->downOne();               //new and improved (level 3 heavy)
                if (extrah1){
                    g1.b->downOne();
                    g1.b->downOne();
                }
            }
            if(player==2){
                g2.b->downOne();
                if (g2.getLevel() >= 3) g2.b->downOne();               //new and improved (level 3 heavy)
                if (extrah2){
                    g2.b->downOne();
                    g2.b->downOne();
                }
            }
        }
        else if(!cmd.compare("clockwise")) { 

            if(player==1){
                g1.b->rotateCw();
                if (g1.getLevel() >= 3) g1.b->downOne();               //new and improved (level 3 heavy)
                if (extrah1){
                    g1.b->downOne();
                    g1.b->downOne();
                }
            }
            if(player==2){
                g2.b->rotateCw();
                if (g2.getLevel() >= 3) g2.b->downOne();               //new and improved (level 3 heavy)
                if (extrah2){
                    g2.b->downOne();
                    g2.b->downOne();
                }
            }
        }
        else if(!cmd.compare("counterclockwise")) { 
            if(player==1){
                g1.b->rotateCcw();
                if (g1.getLevel() >= 3) g1.b->downOne();               //new and improved (level 3 heavy)
                if (extrah1){
                    g1.b->downOne();
                    g1.b->downOne();
                }
            }
            if(player==2){
                g2.b->rotateCcw();
                if (g2.getLevel() >= 3) g2.b->downOne();               //new and improved (level 3 heavy)
                if (extrah2){
                    g2.b->downOne();
                    g2.b->downOne();
                }
            }
        }
        else if(!cmd.compare("drop")) { 
            if(player==1){
                g1.b->drop();
                if(g1.getLevel()>=4) count1++;
                if (extrah1) extrah1 = false;
                if (g1.blind) g1.blind = false;
            }
            if(player==2){
                g2.b->drop();
                if(g2.getLevel()>=4) count2++;
                if (extrah2) extrah2 = false;
                if (g2.blind) g2.blind = false;
            }
            //count goes up per dropped block when level is 4 or more
            
            if (player==1){
                char nextBlock = lev1->genNext(player);
                g1.placeBlock(); // places b down

                int num = g1.remFullRows();
                if (num>0){
                    count1 = 0;
                }
                if (num >=2){
                    std::string spec;
                    std::cout << "Input a special action to inflict on the other player (blind, heavy, force)" << std::endl;
                    cin >> spec;
                    if (!spec.compare("blind")){
                        g2.blind = true;
                    }
                    else if (!spec.compare("heavy")){
                        extrah2 = true;
                    }
                    else if (!spec.compare("force")){
                        char btype;
                        cin >> btype;
                        player = 2;
                        g2.b = genNext(btype);
                        player = 1;
                    }
                }
                else if (count1 % 5 == 0 && count1 > 0) {
                    std::vector<Cell *> positions;
                    positions.push_back(g1.getCell(3, 5));
                    g1.b = std::make_shared<StarBlock>(positions, &g1, g1.getLevel());
                    g1.b->drop();
                    g1.placeBlock();
                }
                g1.b = g1.nextb;
                g1.nextb = genNext(nextBlock);
                lose1 = g1.isGameOver();
            }
            else if (player==2){
                char nextBlock = lev2->genNext(player);
                g2.placeBlock(); // places b down

                int num = g2.remFullRows();
                if (num!=0){
                    count1 = 0;
                }
                if (num >=2){
                    std::string spec;
                    std::cout << "Input a special action to inflict on the other player (blind, heavy, force)" << std::endl;
                    cin >> spec;
                    if (!spec.compare("blind")){
                        g2.blind = true;
                    }
                    else if (!spec.compare("heavy")){
                        extrah2 = true;
                    }
                    else if (!spec.compare("force")){
                        char btype;
                        cin >> btype;
                        player = 1;
                        g1.b = genNext(btype);
                        player = 2;
                    }
                }

                else if (count2 % 5 == 0 && count2 > 0) {
                    std::vector<Cell *> positions;
                    positions.push_back(g2.getCell(3, 5));
                    g2.b = std::make_shared<StarBlock>(positions, &g2, g2.getLevel());
                    g2.b->drop();
                    g2.placeBlock();
                }
                g2.b = g2.nextb;
                g2.nextb = genNext(nextBlock);
                lose2 = g2.isGameOver();
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
            updateLevel();
        }
        else if(!cmd.compare("leveldown")) { 
            if (player==1){
                g1.levelDown();
            }
            if (player==2){
                g2.levelDown();
            }
            updateLevel();
        }
        else if(!cmd.compare("norandom file")) {}
        else if(!cmd.compare("random")) {}
        else if(!cmd.compare("sequence file")) {}
        else if(!cmd.compare("I")) {
            if (player == 1){
                g1.b = genNext('I');
            }
            else{
                g2.b = genNext('I');
            }
        } // for debugging, changes the block to the specified type
        else if(!cmd.compare("J")) {
            if (player == 1){
                g1.b = genNext('J');
            }
            else{
                g2.b = genNext('J');
            }
        }
        else if(!cmd.compare("L")) {
            if (player == 1){
                g1.b = genNext('L');
            }
            else{
                g2.b = genNext('L');
            }
        }
        else if(!cmd.compare("O")) {
            if (player == 1){
                g1.b = genNext('O');
            }
            else{
                g2.b = genNext('O');
            }
        }
        else if(!cmd.compare("S")) {
            if (player == 1){
                g1.b = genNext('S');
            }
            else{
                g2.b = genNext('S');
            }
        }
        else if(!cmd.compare("T")) {
            if (player == 1){
                g1.b = genNext('T');
            }
            else{
                g2.b = genNext('T');
            }
        }
        else if(!cmd.compare("Z")) {
            if (player == 1){
                g1.b = genNext('Z');
            }
            else{
                g2.b = genNext('Z');
            }
        }
        else if(!cmd.compare("*")) {
            if (player == 1){
                std::vector<Cell *> positions;
                positions.push_back(g1.getCell(3, 5));
                g1.b = std::make_shared<StarBlock>(positions, &g1, g1.getLevel());
                g1.b->drop();
                g1.placeBlock();
            }
            else{
                std::vector<Cell *> positions;
                positions.push_back(g2.getCell(3, 5));
                g2.b = std::make_shared<StarBlock>(positions, &g2, g2.getLevel());
                g2.b->drop();
                g2.placeBlock();
            }
        }
        else if (!cmd.compare("blind")){
            // for testing
            if (player == 1){
                g2.blind = true;
            }
            else{
                g1.blind = true;
            }
        }
        else if (!cmd.compare("extrah")){
            // for testing
            if (player == 1){
                extrah2 = true;
            }
            else{
                extrah1 = true;
            }
        }
        else if (!cmd.compare("force")){
            // for testing
            char btype;
            cin >> btype;
            if (player == 1){
                player = 2;
                g2.b = genNext(btype);
                player = 1;
            }
            else{
                player = 1;
                g1.b = genNext(btype);
                player = 2;
            }
        }
        else if(!cmd.compare("restart")) { 
            if (player==1){
                g1.reset();
                lev1 = std::make_shared<LevelZero>();
                g1.b = genNext(lev1->genNext(player));
                g1.nextb = genNext(lev1->genNext(player));
            }
            if (player==2){
                g2.reset();
                lev2 = std::make_shared<LevelZero>();
                g2.b = genNext(lev2->genNext(player));
                g2.nextb = genNext(lev2->genNext(player));
            }
        }
        
        td->showText(&g1, &g2);
    }
}

std::shared_ptr<Block> Biquadris::genNext(char nextBlock){
    std::vector<Cell *> positions; // cells in grid that will contain block
    std::shared_ptr<Block> newBlock;
    if(nextBlock == 'i'||nextBlock == 'I') {
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
    else if(nextBlock == 'j'||nextBlock == 'J') {
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
    else if(nextBlock == 'l'||nextBlock == 'L') {
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
    else if(nextBlock == 'o'||nextBlock == 'O') {
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
    else if(nextBlock == 's'||nextBlock == 'S') {
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
    else if(nextBlock == 't'||nextBlock == 'T') {
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
    else if(nextBlock == 'z'||nextBlock == 'Z') {
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
    if (lose1){
        g1.reset();
        lev1 = std::make_shared<LevelZero>();
        g1.b = genNext(lev1->genNext(1));
        g1.nextb = genNext(lev1->genNext(1));
        lose1=false;
    }
    if (lose2){
        g2.reset();
        lev2 = std::make_shared<LevelZero>();
        g2.b = genNext(lev2->genNext(2));
        g2.nextb = genNext(lev2->genNext(2));
        lose2=false;
    }
    if(player == 1) player = 2;
    else player = 1;
}

void Biquadris::updateLevel(){
    if (player == 1){
        if (g1.getLevel()==0){
            lev1 = std::make_shared<LevelZero>();
        }
        else if (g1.getLevel()==1){
            lev1 = std::make_shared<LevelOne>();
        }
        else if (g1.getLevel()==2){
            lev1 = std::make_shared<LevelTwo>();
        }
        else if (g1.getLevel()==3){
            lev1 = std::make_shared<LevelThree>();
        }
        else if (g1.getLevel()==4){
            lev1 = std::make_shared<LevelFour>();
        }
    }
    else if (player == 2){
        if (g2.getLevel()==0){
            lev2 = std::make_shared<LevelZero>();
        }
        else if (g2.getLevel()==1){
            lev2 = std::make_shared<LevelOne>();
        }
        else if (g2.getLevel()==2){
            lev2 = std::make_shared<LevelTwo>();
        }
        else if (g2.getLevel()==3){
            lev2 = std::make_shared<LevelThree>();
        }
        else if (g2.getLevel()==4){
            lev2 = std::make_shared<LevelFour>();
        }
    }
}