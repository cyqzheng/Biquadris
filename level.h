#ifndef LEVEL_H
#define LEVEL_H
#include <memory>

class Block;

class Level { 
	std::shared_ptr<Block> curr1; //remember the constructor needs to update curr1 or curr2 after calling genNext!
	std::shared_ptr<Block> curr2;

	public:

	bool setseed = false;
	int seed = 0;
	bool random = true;
    std::string f = "sequence1.txt";

	Level();
	virtual int getLevel() = 0;
	virtual bool getHeavy() = 0;
	//virtual Block getNextBlock() = 0;
	virtual char genNext(int s) = 0; //s is which player is playing (1 or 2)

	std::shared_ptr<Block> getCurBlock(int s);//s is which player is playing (1 or 2)
	void setCurBlock(std::shared_ptr<Block> b, int s);
	void updateBlock();
	void updateGrid();

};

#endif
