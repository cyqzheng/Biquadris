#include <iostream>
#include <cstdlib>
#include <string>
#include "levelfour.h"
//#include "block.h"


int LevelFour::getLevel(){return 4;}
bool LevelFour::getHeavy(){return false;}
//Block LevelFour::getNextBlock();
char LevelFour::genNext(int s){
        char nextBlock = 'e';
        int n = (rand() % 9) + 1; // 1,2 S  3,4 Z  5 I  6 J  7 L  8 O  9 T
	if (n == 1 || n == 2){
                nextBlock = 's';       // this code gives me anxiety
        }
        else if (n == 3 || n == 4){
                nextBlock = 'z'; 
        }
        else if (n == 5){
                nextBlock = 'i'; 
        }
        else if (n == 6){
                nextBlock = 'j'; 
        }
        else if (n == 7){
                nextBlock = 'l'; 
        }
        else if (n == 8){
                nextBlock = 'o'; 
        }
        else if (n == 9){
                nextBlock = 't'; 
        }

        return nextBlock;  //theoretically this should never happen...
                     //should probs make exception to throw if we reach end without anything to return
}
