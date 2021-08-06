#ifndef LEVELZERO_H
#define LEVELZERO_H

#include <fstream>
#include <vector>
#include "level.h"
class Block;

class LevelZero : public Level{
	std::istream *seq1 = new std::ifstream{"sequence1.txt"};
	std::istream *seq2 = new std::ifstream{"sequence2.txt"};
        public:
	LevelZero(std::string s1 = "", std::string s2 = ""); // if only new seq2 is given initialize s1 as "" ?
        ~LevelZero();
	int getLevel() override;
        bool getHeavy() override;
        //Block getNextBlock() override;
        Block genNext(int s) override;

};

#endif 
