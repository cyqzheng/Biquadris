#ifndef LEVEL_H
#define LEVEL_H
#include "block.h"

class Block;

class Level { 
	Block curr1; //remember the constructor needs to update curr1 or curr2 after calling genNext!
	Block curr2;
	public:
	Level();
	virtual int getLevel() = 0;
	virtual bool getHeavy() = 0;
	//virtual Block getNextBlock() = 0;
	virtual char genNext(int s) = 0; //s is which player is playing (1 or 2)

	Block getCurBlock(int s);//s is which player is playing (1 or 2)
	void setCurBlock(Block b, int s);
	void updateBlock();
	void updateGrid();

};

#endif
