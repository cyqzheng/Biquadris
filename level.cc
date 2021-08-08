#include <iostream>
#include "level.h"
#include "block.h"

Block Level::getCurBlock(int s){
	if (s == 1) return curr1;
	return curr2;
}
void Level::setCurBlock(Block b, int s){
	if (s == 1) curr1 = b;
	else curr2 = b;
}
void Level::updateBlock(){};
void Level::updateGrid(){};
