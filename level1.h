#ifndef _LEVEL1_H_
#define _LEVEL1_H_
#include <iostream>
#include <string>
#include "level.h"
#include "block.h"

using namespace std;

class Level1 : public Level {
    public:
        Level1();
        Block* getBlock(size_t i) override;
        size_t getLevel() override;

};

#endif
