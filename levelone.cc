#include <iostream>
#include <cstdlib>
#include <string>
#include "levelone.h"
//#include "block.h"


int LevelOne::getLevel(){return 1;}
bool LevelOne::getHeavy(){return false;}
Block LevelOne::getNextBlock();
Block LevelOne::genNext(int s){
	std::string newBlock;
	// srand(time(0));         remember this line in controller
	int n = (rand() % 12) + 1; // 1 S  2 Z  3,4 I  5,6 J  7,8 L  9,10 O  11,12 T
	if (n == 1){
		SBlock theBlock;
		return theBlock;        // this code gives me anxiety
	}
	else if (n == 2){
                ZBlock theBlock;
                return theBlock;
	}
	else if (n == 3 || n == 4){
                IBlock theBlock;
                return theBlock;
        }
	else if (n == 5 || n == 6){
                JBlock theBlock;
                return theBlock;
        }
	else if (n == 7 || n == 8){
                LBlock theBlock;
                return theBlock;
        }
	else if (n == 9 || n == 10){
                OBlock theBlock;
                return theBlock;
        }
	else if (n == 11 || n == 12){
                TBlock theBlock;
                return theBlock;
        }

	Block fake;
	return fake; //theoretically this should never happen...
		     //should probs make exception to throw if we reach end without anything to return
}




