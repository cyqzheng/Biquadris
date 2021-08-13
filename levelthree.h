#ifndef LEVELTHREE_H
#define LEVELTHREE_H

#include <fstream>
#include <vector>
#include <string>
#include "level.h"
class Block;

class LevelThree : public Level{
        std::shared_ptr<std::istream> seq;
        public:
        //LevelZero();
        //~LevelZero();
        int getLevel() override;
        bool getHeavy() override;
        //Block getNextBlock() override;
        char genNext(int s) override;

};

#endif
