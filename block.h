#ifndef _BLOCK_H_
#define _BLOCK_H_
#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Block implements 

class Block {
    // current orientation (coordinates) of the 4 pieces of the block 
    // std::vector<std::vector<int>> structure;

 public:
 // we don't need to explicitly define the 3D vector as private field
 // orientation determined by a 3D vector
        std::vector<std::vector<std::vector<int>>> orientation;
        /*
        std::vector<std::vector<std::vector<int>>> bottomMost;
        std::vector<std::vector<std::vector<int>>> leftMost;
        std::vector<std::vector<std::vector<int>>> rightMost;*/
        // movement of blocks not determined yet
        size_t x;
        size_t y;

        // character the block is made up of: I, J, L, O, S, Z, T
        char c;

        // current index in orientation vector
        size_t i;
        virtual std::vector<std::vector<int>> getStructure() = 0;
        /*
        virtual std::vector<std::vector<int>> getbottomMost() = 0;
        virtual std::vector<std::vector<int>> getleftMost() = 0;
        virtual std::vector<std::vector<int>> getRightMost() = 0;*/
        virtual void moveBlockRight() = 0;
        virtual void moveBlockLeft() = 0;      // change x
        virtual void moveBlockDown() = 0;       // change y
        virtual char getBlockType() = 0;     // return c
        virtual void rotateClockWise() = 0;  // changes the 2D vector structure and size_t i equal to new index
        virtual void rotateCounterClockWise() = 0;

};
#endif

