#include <iostream>
#include <cstdlib>
#include "leveltwo.h"
//#include "block.h"


int LevelTwo::getLevel(){return 2;}
bool LevelTwo::getHeavy(){return false;}
//Block LevelTwo::getNextBlock();
char LevelTwo::genNext(int s){
	std::string newBlock;
	//srand(time(0));        remember this line in controller
        char nextBlock = 'e';
	int n = (rand() % 7) + 1; 
	if (n == 1){
		nextBlock = 's';       // this code gives me anxiety
	}
	else if (n == 2){
                nextBlock = 'z'; 
	}
	else if (n == 3){
                nextBlock = 'i';
        }
	else if (n == 4){
                nextBlock = 'j';
        }
	else if (n == 5){
                nextBlock = 'l';
        }
	else if (n == 6){
                nextBlock = 'o';
        }
	else if (n == 7){
                nextBlock = 't';
        }
        return nextBlock; // theoretically this should never happen...
		        // should probs make exception to throw if we reach end without anything to return
}




