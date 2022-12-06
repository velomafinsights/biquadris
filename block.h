#ifndef _BLOCK_H_
#define _BLOCK_H_
#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Block implements 

class Block {

 public:
        Block(char c);
        std::vector<std::vector<std::vector<int>>> orientation;
        std::vector<int> blockWidth;
        std::vector<std::vector<std::vector<int>>> bottomMost;
        std::vector<std::vector<std::vector<int>>> leftMost;
        std::vector<std::vector<std::vector<int>>> rightMost;

        // movement of blocks not determined yet
        size_t x;
        size_t y;

        size_t currLevel;
        // character the block is made up of: I, J, L, O, S, Z, T
        char c;

        bool blockCleared;

        // current index in orientation vector
        size_t i;
        std::vector<std::vector<int>> getStructure();
        //clockwise
        std::vector<std::vector<int>> getNextCWOrientation();
        //counterclockwise
        std::vector<std::vector<int>> getNextCCWOrientation();    

        std::vector<std::vector<int>> getbottomMost();
        std::vector<std::vector<int>> getleftMost();
        std::vector<std::vector<int>> getRightMost();
        int blockRemoved();
        void rowCleared(int row);
        void moveBlockRight();
        void moveBlockLeft();      // change x
        void moveBlockDown();       // change y
        char getBlockType();     // return c
        void rotateClockWise();  // changes the 2D vector structure and size_t i equal to new index
        void rotateCounterClockWise();
        void setCurrLevel(size_t level);
        int getX();
        int getY();

};
#endif

