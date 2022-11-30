#ifndef _LEVEL3_H_
#define _LEVEL3_H_
#include <iostream>
#include <string>
#include "level.h"
#include "block.h"

using namespace std;

class Level3 : public Level {
    string seqOneSource;
    ifstream seqOne;
    bool queueFromFile;     // queueFromFile = 1: take from provided file, queueFromFile = 0, call from random
    size_t seqOneLength;
    public:
        std::vector<string> blockQueue;
        Level3(bool queueFromFile, std::string seqOneSource = "sequence1.txt");
        void setBlockQueue();
        Block* getBlock(size_t i) override;
        size_t getLevel() override;

};

#endif
