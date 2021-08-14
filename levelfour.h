#ifndef LEVELFOUR_H
#define LEVELFOUR_H

#include <fstream>
#include <vector>
#include "level.h"
class Block;

class LevelFour : public Level{
        std::shared_ptr<std::istream> seq;
        public:
        //LevelZero();
        //~LevelZero();
        int getLevel() override;
        bool getHeavy() override;
        //Block getNextBlock() override;
        char genNext(int s) override;
        void setseq() override;

};

#endif
