#include <iostream>
#include <cstdlib>
#include "leveltwo.h"
//#include "block.h"


int LevelTwo::getLevel(){return 2;}
bool LevelTwo::getHeavy(){return false;}
Block LevelTwo::getNextBlock();
Block LevelTwo::genNext(int s){
	std::string newBlock;
	//srand(time(0));        remember this line in controller
	int n = (rand() % 7) + 1; 
	if (n == 1){
		SBlock theBlock;
		return theBlock;        // this code gives me anxiety
	}
	else if (n == 2){
                ZBlock theBlock;
                return theBlock;
	}
	else if (n == 3){
                IBlock theBlock;
                return theBlock;
        }
	else if (n == 4){
                JBlock theBlock;
                return theBlock;
        }
	else if (n == 5){
                LBlock theBlock;
                return theBlock;
        }
	else if (n == 6){
                OBlock theBlock;
                return theBlock;
        }
	else if (n == 7){
                TBlock theBlock;
                return theBlock;
        }

	Block fake;
	return fake; //theoretically this should never happen...
		     //should probs make exception to throw if we reach end without anything to return
}




