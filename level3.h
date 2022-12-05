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
    
    // if queueFromFile = 1, getBlock follows the provided file, else getBlock follows probability model for level 3
    bool queueFromFile;
    
    size_t seqOneLength;
    public:
        std::vector<string> blockQueue;
        Level3(bool queueFromFile, std::string seqOneSource = "sequence1.txt");
        void setBlockQueue();
        Block* getBlock(size_t i) override;
        size_t getLevel() override;

};

#endif
