#ifndef _LEVEL_H_
#define _LEVEL_H_

// #include "gameboard.h"
#include "block.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

class Level {
    size_t level;
   

    public:
        std::vector<string> blockQueue;
        virtual vector<vector<int>> getblock(size_t i) = 0;
        virtual size_t getLevel() = 0;
        virtual ~Level();
};

#endif
