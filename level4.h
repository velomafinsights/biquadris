#ifndef _LEVEL4_H_
#define _LEVEL4_H_
#include <iostream>
#include <string>
#include "level.h"
#include "block.h"

// how do we find how many times we've placed 5 blocks?

using namespace std;

// first set up Level4 exactly as Level3

class Level4 : public Level {
    string seqOneSource;
    ifstream seqOne;
    bool queueFromFile;     // queueFromFile = 1: take from provided file, queueFromFile = 0, call from random
    size_t seqOneLength;

    public:
        std::vector<string> blockQueue;
        Level4(bool queueFromFile, std::string seqOneSource = "sequence1.txt");
        void setBlockQueue();
        Block* getBlock(size_t i) override;
        size_t getLevel() override;

};

#endif

