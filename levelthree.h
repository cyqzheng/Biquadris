#ifndef LEVELTHREE_H
#define LEVELTHREE_H

#include <fstream>
#include <vector>
#include "level.h"
class Block;

class LevelThree : public Level{
        public:
        //LevelZero();
        //~LevelZero();
        int getLevel() override;
        bool getHeavy() override;
        //Block getNextBlock() override;
        Block genNext(int s) override;

};

#endif
