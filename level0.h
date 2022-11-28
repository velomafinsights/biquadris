#ifndef _LEVEL0_H_
#define _LEVEL0_H_
#include <iostream>
#include <fstream>
#include <string>
#include "level.h"
#include "block.h"

using namespace std;

class Level0 : public Level {

    string seqOneSource;
    string blockQItem;
    //string seqTwoSource;
    ifstream seqOne; //the sequence1.txt file we use to find the next block
    //ifstream seqTwo;
    size_t seqOneLength;
    public:
        std::vector<string> blockQueue;

        Level0(std::string seqOneSource);
        void setBlockQueue();
        Block* getBlock(size_t i) override;
        size_t getLevel() override;
    
};

#endif

