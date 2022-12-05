#ifndef _LEVEL2_H_
#define _LEVEL2_H_
#include <iostream>
#include <string>
#include "level.h"
#include "block.h"

using namespace std;

class Level2 : public Level {

    public:
        Block* getBlock(size_t i) override;
        size_t getLevel() override;

};

#endif
