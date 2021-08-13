#ifndef LEVELZERO_H
#define LEVELZERO_H

#include <fstream>
#include <vector>
#include <memory>
#include "level.h"
class Block;

class LevelZero : public Level{
	std::shared_ptr<std::istream> seq1;
        std::shared_ptr<std::istream> seq2;

        public:
	LevelZero(std::string s1 = "", std::string s2 = ""); // if only new seq2 is given initialize s1 as "" ?
        ~LevelZero();
	int getLevel() override;
        bool getHeavy() override;
        //Block getNextBlock() override;
        char genNext(int s) override;

};

#endif 
