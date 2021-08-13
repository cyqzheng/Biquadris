#ifndef LEVELONE_H
#define LEVELONE_H

#include <fstream>
#include <vector>
#include "level.h"
class Block;

class LevelOne : public Level{
        public:
	//LevelZero();
        //~LevelZero();
	int getLevel() override;
        bool getHeavy() override;
        //Block getNextBlock() override;
        char genNext(int s) override;

};

#endif 
