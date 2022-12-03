#ifndef _BLOCKSTAR__
#define _BLOCKSTAR__
#include "block.h"

class blockStar: public Block {
    public: 
        blockStar();
        std::vector<std::vector<std::vector<int>>> orientation;
        std::vector<int> blockWidth;
        std::vector<std::vector<std::vector<int>>> bottomMost;
        std::vector<std::vector<std::vector<int>>> leftMost;
        std::vector<std::vector<std::vector<int>>> rightMost;


        void moveBlockDown(); 
        int blockRemoved();
        void rowCleared(int row);
        // movement of blocks not determined yet
        size_t x;
        size_t y;

        size_t currLevel;
        // character the block is made up of: I, J, L, O, S, Z, T
        char c = '*';

        // current index in orientation vector
        size_t i;

};

#endif
