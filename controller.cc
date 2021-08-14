#include <iostream>
#include <string>
#include "controller.h"

using std::cin;
using std::getline;

//Biquadris::Biquadris(){}
Biquadris::Biquadris(int width, int height, bool graphics) : width{width}, height{height}, graphics{graphics} {
    td = std::make_shared<TextDisplay>(width, height);
    window = std::make_shared<Graphics>(width, height, &g1, &g2);
    g1.window = window;
    g2.window = window;
    g1.player = 1;
    g2.player = 2;
    g1.graphics = graphics;
    g2.graphics = graphics;
    lev1 = std::make_shared<LevelZero>();
    lev2 = std::make_shared<LevelZero>();
}

void Biquadris::run() {
    std::string cmd;
    int count1 = 0;                                              //count1: number of block placements since last row clear for p1
    int count2 = 0;
    bool extrah1 = false;
    bool extrah2 = false;
    int multiplier=0;
    std::shared_ptr<std::ifstream>seq;
    std::vector<Cell *> oldpositions;

    g1.graphics = graphics;
    g2.graphics = graphics;
    if (graphics) g1.window = window;
    if (graphics) g2.window = window;


    if (graphics) std::cout << "Graphics are on" << std::endl;
    else std::cout << "Graphics are off" << std::endl;

    player = 1;
    updateLevel();
    g1.b = genNext(lev1->genNext(player));
    g1.nextb = genNext(lev1->genNext(player));

    player = 2;
    updateLevel();
    g2.b = genNext(lev2->genNext(player));
    g2.nextb = genNext(lev2->genNext(player));

    player = 1;
    td->showText(&g1, &g2);
    if (graphics) window->showWindow();

    if (!seqfile) cin >> cmd;
    else{
        seq = std::make_shared<std::ifstream>(f);
        char nextBlock = 'e';
        std::string newcmd;
	    seq->exceptions(std::ios::eofbit|std::ios::failbit);
        try{
			*seq >> newcmd;
            cmd = newcmd;
        }
        catch(std::ios_base::failure&){
            seqfile = false; // done going through file
            std::cout << "Seq file complete. Please input more commands: \n";
            cin >> cmd;
        }
    }

    while (cin) {
        int i=0;

        multiplier = 0;
        while(cmd[i] >= '0' && cmd[i] <= '9') {
            multiplier = multiplier * 10 + (cmd[i] - '0');
            ++i;
        }
        if (multiplier==0){
            multiplier = 1;
        }
        
        cmd = cmd.substr(i, std::string::npos);
        std::string shortcmd3 = cmd, shortcmd2 = cmd, shortcmd6 = cmd;

        if(cmd.length()>3) shortcmd3 = cmd.substr(0,3);
        if(cmd.length()>2) shortcmd2 = cmd.substr(0,2);
        if(cmd.length()>6) shortcmd6 = cmd.substr(0,6);

        if(!shortcmd3.compare("lef")) {
            // get block in the grid and manipulate it
            if(player==1){
                oldpositions = g1.b->position;
                for (int k=0; k<multiplier; ++k){
                    g1.b->left();
                    if (g1.getLevel() >= 3) g1.b->downOne();               //new and improved (level 3 heavy)
                    if (extrah1){
                        g1.b->downOne();
                        g1.b->downOne();
                    }
                }
            }
            if(player==2){
                oldpositions = g2.b->position;
                for (int k=0; k<multiplier; ++k){
                    g2.b->left();
                    if (g2.getLevel() >= 3) g2.b->downOne();               //new and improved (level 3 heavy)
                    if (extrah2){
                        g2.b->downOne();
                        g2.b->downOne();
                    }
                }
            }
            
        }
        else if(!shortcmd2.compare("ri")) { 
            
            if(player==1){
                oldpositions = g1.b->position;
                for (int k=0; k<multiplier; ++k){
                    g1.b->right();
                    if (g1.getLevel() >= 3) g1.b->downOne();               //new and improved (level 3 heavy)
                    if (extrah1){
                        g1.b->downOne();
                        g1.b->downOne();
                    }
                }
            }
            if(player==2){
                oldpositions = g2.b->position;
                for (int k=0; k<multiplier; ++k){
                    g2.b->right();
                    if (g2.getLevel() >= 3) g2.b->downOne();               //new and improved (level 3 heavy)
                    if (extrah2){
                        g2.b->downOne();
                        g2.b->downOne();
                    }
                }
            }
        }
        else if(!shortcmd2.compare("do")) { 
            if(player==1){
                oldpositions = g1.b->position;
                for (int k=0; k<multiplier; ++k){
                    g1.b->downOne();
                    if (g1.getLevel() >= 3) g1.b->downOne();               //new and improved (level 3 heavy)
                    if (extrah1){
                        g1.b->downOne();
                        g1.b->downOne();
                    }
                }
            }
            if(player==2){
                oldpositions = g2.b->position;
                for (int k=0; k<multiplier; ++k){
                    g2.b->downOne();
                    if (g2.getLevel() >= 3) g2.b->downOne();               //new and improved (level 3 heavy)
                    if (extrah2){
                        g2.b->downOne();
                        g2.b->downOne();
                    }
                }
            }
        }
        else if(!shortcmd2.compare("cl")) { 
            
            if(player==1){
                oldpositions = g1.b->position;
                for (int k=0; k<multiplier; ++k){
                    g1.b->rotateCw();
                    if (g1.getLevel() >= 3) g1.b->downOne();               //new and improved (level 3 heavy)
                    if (extrah1){
                        g1.b->downOne();
                        g1.b->downOne();
                    }
                }
            }
            if(player==2){
                oldpositions = g2.b->position;
                for (int k=0; k<multiplier; ++k){
                    g2.b->rotateCw();
                    if (g2.getLevel() >= 3) g2.b->downOne();               //new and improved (level 3 heavy)
                    if (extrah2){
                        g2.b->downOne();
                        g2.b->downOne();
                    }
                }
            }
        }
        else if(!shortcmd2.compare("co")) { 
            for (int k=0; k<multiplier; ++k){
                if(player==1){
                    oldpositions = g1.b->position;
                    g1.b->rotateCcw();
                    if (g1.getLevel() >= 3) g1.b->downOne();               //new and improved (level 3 heavy)
                    if (extrah1){
                        g1.b->downOne();
                        g1.b->downOne();
                    }
                }
                if(player==2){
                    oldpositions = g2.b->position;
                    g2.b->rotateCcw();
                    if (g2.getLevel() >= 3) g2.b->downOne();               //new and improved (level 3 heavy)
                    if (extrah2){
                        g2.b->downOne();
                        g2.b->downOne();
                    }
                }
            }
        }
        else if(!shortcmd2.compare("dr")) {
            for (int k=0; k<multiplier; ++k){ 
                if(player==1){
                    oldpositions = g1.b->position;
                    g1.b->drop();
                    if(g1.getLevel()>=4) count1++;
                    if (extrah1) extrah1 = false;
                    if (g1.blind){
                        g1.blind = false;
                        if (graphics) window->showWindow();
                    }
                }
                if(player==2){
                    oldpositions = g2.b->position;
                    g2.b->drop();
                    if(g2.getLevel()>=4) count2++;
                    if (extrah2) extrah2 = false;
                    if (g2.blind){
                        g2.blind = false;
                        if (graphics) window->showWindow();
                    }
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
                            if (graphics) window->showWindow();
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
                    if (graphics) window->updateBlock(player, oldpositions);
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
                            if (graphics) window->showWindow();
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
                    if (graphics) window->updateBlock(player, oldpositions);
                    g2.b = g2.nextb;
                    g2.nextb = genNext(nextBlock);
                    lose2 = g2.isGameOver();
                }
                if (graphics) window->updateBlock(player, oldpositions);
                if (graphics) window->updateNextBlock(player);
                
            }
            this->switchPlayer();
        }
        else if(!shortcmd6.compare("levelu")) { 
            for (int k=0; k<multiplier; ++k){
                if (player==1){
                    g1.levelUp();
                }
                if (player==2){
                    g2.levelUp();
                }
                updateLevel();
            }
            if (graphics) window->levelupdate();
        }
        else if(!shortcmd6.compare("leveld")) { 
            for (int k=0; k<multiplier; ++k){
                if (player==1){
                    g1.levelDown();
                }
                if (player==2){
                    g2.levelDown();
                }
                updateLevel();
            }
            if (graphics) window->levelupdate();
        }
        else if(!shortcmd2.compare("no")) {
            std::string s;
            cin >> s;
            if (player == 1){
                if (g1.level>=3){
                    lev1->random = false;
                    lev1->f = s;
                }
                
            }
            if (player == 2){
                if (g2.level>=3){
                    lev2->random = false;
                    lev2->f = s;
                }
                
            }
            //std::string s1 = std::ifstream{file};
        }
        else if(!shortcmd2.compare("ra")) {
            // set random bool variable to turn randomness on and off
            if (player == 1){
                lev1->random = true;
            }
            else{
                lev2->random = true;
            }
        }
        else if(!shortcmd2.compare("se")) {
            // get file name and then set the new file sequence in Level
            cin >> f;
            seqfile = true;
        }
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
        else if(!shortcmd2.compare("re")) { 
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
        if (graphics) window->updateBlock(player, oldpositions);
        if (graphics) window->updateNextBlock(player);
        if (graphics) window->levelupdate();
        if (graphics) window->scoreupdate();

        // get next command
        if (!seqfile) cin >> cmd;
        else{
            seq = std::make_shared<std::ifstream>(f);
            char nextBlock = 'e';
            std::string newcmd;
            seq->exceptions(std::ios::eofbit|std::ios::failbit);
            try{
                *seq >> newcmd;
                cmd = newcmd;
            }
            catch(std::ios_base::failure&){
                seqfile = false; // done going through file
                std::cout << "Seq file complete. Please input more commands: \n";
                cin >> cmd; // get from co
            }
        }
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
            if (f1!="" && f2 !=""){
                lev1 = std::make_shared<LevelZero>(f1, f2);
            }
            else if (f1!=""){
                lev1 = std::make_shared<LevelZero>(f1);
            }
            else if (f2!=""){
                lev1 = std::make_shared<LevelZero>("sequence1.txt",f2);
            }
            else lev1 = std::make_shared<LevelZero>();
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
            if (f1!="" && f2 !=""){
                lev2 = std::make_shared<LevelZero>(f1, f2);
            }
            else if (f1!=""){
                lev2 = std::make_shared<LevelZero>(f1);
            }
            else if (f2!=""){
                lev2 = std::make_shared<LevelZero>("sequence1.txt",f2);
            }
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