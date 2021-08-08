#include <iostream>
#include <cstdlib>
#include <string>
#include "levelthree.h"
//#include "block.h"


int LevelThree::getLevel(){return 3;}
bool LevelThree::getHeavy(){return true;}
Block LevelThree::getNextBlock();
Block LevelThree::genNext(int s){
        std::string newBlock;
        int n = (rand() % 9) + 1; // 1,2 S  3,4 Z  5 I  6 J  7 L  8 O  9 T
	if (n == 1 || n == 2){
                SBlock theBlock;
                return theBlock;        // this code gives me anxiety
        }
        else if (n == 3 || n == 4){
                ZBlock theBlock;
                return theBlock;
        }
        else if (n == 5){
                IBlock theBlock;
                return theBlock;
        }
        else if (n == 6){
                JBlock theBlock;
                return theBlock;
        }
        else if (n == 7){
                LBlock theBlock;
                return theBlock;
        }
        else if (n == 8){
                OBlock theBlock;
                return theBlock;
        }
        else if (n == 9){
                TBlock theBlock;
                return theBlock;
        }

        Block fake;
        return fake; //theoretically this should never happen...
                     //should probs make exception to throw if we reach end without anything to return
}
