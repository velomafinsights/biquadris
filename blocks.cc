#include "blocks.h"

BlockS::BlockS(){
    vector<vector<int>> s0 = {{2,1}, {2,2}, {3,0}, {3,1}};
    vector<vector<int>> s1 = {{1,0}, {2,0}, {2,1}, {3,1}};
    orientation = {s0, s1, s0, s1};
    // create 2D vectors
    // add to 3D vec orientation
   /*std::vector<std::vector<std::vector<int>>> bottomMost;
        std::vector<std::vector<std::vector<int>>> leftMost;
        std::vector<std::vector<std::vector<int>>> rightMost; */
    
    vector<vector<int>> b0 = {{2,2}, {3,0}, {3,1}};
    vector<vector<int>> b1 = {{2,0}, {3,1}};
    bottomMost = {b0, b1, b0, b1};
    
    vector<vector<int>> l0 = {{2,1}, {3,0}};
    vector<vector<int>> l1 = {{1,0}, {2,0}, {3,1}};
    leftMost = {l0, l1, l0, l1};

    vector<vector<int>> r0 = {{2,2}, {3,1}};
    vector<vector<int>> r1 = {{1,0}, {2,1}, {3,1}};
    rightMost = {r0, r1, r0, r1};

    x = 0;
    y = 3;
    c = 's';
    i = 0;
}

char BlockS::getBlockType(){
    return c;
}

void BlockS::rotateClockWise(){
    if (i == 3) i = 0;
    else{
        ++i;
    }
}

void BlockS::rotateCounterClockWise(){
    if (i == 0) i = 3;
    else{
        --i;
    }
}

void BlockS::moveBlockRight(){
    // create a check for out of range
    // create a check for current orientation and max width
    if (i == 0 || i == 2){
        if (x < 8){
            ++x;
        }
    }
    else{
        if (x < 9){
            ++x;
        }
    }
}

void BlockS::moveBlockLeft(){
    if (x > 0){
        --x;
    }
}

void BlockS::moveBlockDown(){
    --y;
}

std::vector<std::vector<int>> BlockS::getStructure(){
    return orientation[i];
}

/*
virtual std::vector<std::vector<int>> getbottomMost() = 0;
        virtual std::vector<std::vector<int>> getleftMost() = 0;
        virtual std::vector<std::vector<int>> getRightMost() = 0;
*/

std::vector<std::vector<int>> BlockS::getbottomMost(){
    return bottomMost[i];
}

std::vector<std::vector<int>> BlockS::getleftMost(){
    return leftMost[i];
}

std::vector<std::vector<int>> BlockS::getRightMost(){
    return rightMost[i];
}


