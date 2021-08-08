#ifndef LEVELFOUR_H
#define LEVELFOUR_H

#include <fstream>
#include <vector>
#include "level.h"
class Block;

class LevelFour : public Level{
        public:
        //LevelZero();
        //~LevelZero();
        int getLevel() override;
        bool getHeavy() override;
        //Block getNextBlock() override;
        Block genNext(int s) override;

};

#endif
