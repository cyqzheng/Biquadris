#ifndef LEVELTWO_H
#define LEVELTWO_H

#include <fstream>
#include <vector>
#include "level.h"
class Block;

class LevelTwo : public Level{
	public:
	int getLevel() override;
        bool getHeavy() override;
        //Block getNextBlock() override;
        Block genNext(int s) override;

};

#endif 
