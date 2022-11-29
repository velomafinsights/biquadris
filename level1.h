#ifndef _LEVEL0_H_
#define _LEVEL0_H_
#include <iostream>
#include <fstream>
#include <string>
#include "level.h"
#include "block.h"

using namespace std;

// give probability 1/12 for S and Z
// and 1/6 for O, L, I, J, T

class Level1 : public Level {

    public:
        Block* getBlock(size_t i) override;
        size_t getLevel() override;

};

#endif
