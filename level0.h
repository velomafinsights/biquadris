#ifndef _LEVEL0_H_
#define _LEVEL0_H_
#include <iostream>
#include <fstream>
#include <string>
#include "level.h"
#include "block.h"

using namespace std;

class Level0 : public Level {
    //
    string seqOneSource;
    //string seqTwoSource;
    ifstream seqOne; //the sequence1.txt file we use to find the next block
    //ifstream seqTwo;
    size_t seqOneLength;
    public:
        Level0(std::string seqOneSource);
        void setBlockQueue();
        // the index is determined by the client using getBlock: 0 <= i <=3
        Block* getBlock(size_t i);
        //Block* getBlock(size_t i);
        size_t getLevel() override;
    
};

#endif

