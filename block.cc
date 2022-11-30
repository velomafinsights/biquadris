#include "block.h"

Block::Block(char c): c{c}{
    if(c == 's'){
        vector<vector<int>> s0 = {{2,1}, {2,2}, {3,0}, {3,1}};
        vector<vector<int>> s1 = {{1,0}, {2,0}, {2,1}, {3,1}};
        orientation = {s0, s1, s0, s1};
        
        blockWidth = {2, 2};

        vector<vector<int>> b0 = {{2,2}, {3,0}, {3,1}};
        vector<vector<int>> b1 = {{2,0}, {3,1}};
        bottomMost = {b0, b1, b0, b1};
    } else if (c == 'i'){
        vector<vector<int>> s0 = {{3,0}, {3,1}, {3,2}, {3,3}}; //Original starting position
        vector<vector<int>> s1 = {{0,0}, {1,0}, {2,0}, {3,0}};//Clockwise
        orientation = {s0, s1, s0, s1};
        
        blockWidth = {4, 1};
        
        vector<vector<int>> b0 = {{3,0}, {3,1}, {3,2}, {3,3}};
        vector<vector<int>> b1 = {{3, 0}};
        bottomMost = {b0, b1, b0, b1};

    } else if (c == 'j'){
        vector<vector<int>> s0 = {{2,0}, {3,0}, {3,1}, {3,2}}; //Original starting position
        vector<vector<int>> s1 = {{1,0}, {1,1}, {2,0}, {3,0}}; //  1 Clockwise
        vector<vector<int>> s2 = {{2,0}, {2,1}, {2,2}, {3,2}}; //  2 Clockwise
        vector<vector<int>> s3 = {{3,0}, {1,1}, {2,1}, {3,1}}; //  3 Clockwise
        orientation = {s0, s1, s2, s3};

        blockWidth = {3, 2};

        vector<vector<int>> b0 = {{3,0}, {3,1}, {3,2}};
        vector<vector<int>> b1 = {{1,1}, {3,0}};
        vector<vector<int>> b2 = {{2,0}, {2,1}, {3,2}};
        vector<vector<int>> b3 = {{3,0}, {3,1}};
        bottomMost = {b0, b1, b2, b3};
    } else if (c == 'l'){
        vector<vector<int>> s0 = {{2,2}, {3,0}, {3,1}, {3,2}}; //Original starting position
        vector<vector<int>> s1 = {{1,0}, {3,1}, {2,0}, {3,0}}; //  1 Clockwise
        vector<vector<int>> s2 = {{2,0}, {2,1}, {2,2}, {3,0}}; //  2 Clockwise
        vector<vector<int>> s3 = {{1,0}, {1,1}, {2,1}, {3,1}}; //  3 Clockwise
        orientation = {s0, s1, s2, s3};

        blockWidth = {3, 2};

        vector<vector<int>> b0 = {{3,0}, {3,1}, {3,2}};
        vector<vector<int>> b1 = {{3,1}, {3,0}};
        vector<vector<int>> b2 = {{3,0}, {2,1}, {2,2}};
        vector<vector<int>> b3 = {{3,0}, {3,1}};
        bottomMost = {b0, b1, b2, b3};
    } else if (c == 'z') {
        vector<vector<int>> s0 = {{2,0}, {2,1}, {3,1}, {3,2}};
        vector<vector<int>> s1 = {{1,1}, {2,0}, {2,1}, {3,0}};
        orientation = {s0, s1, s0, s1};

        blockWidth = {2, 2};

        vector<vector<int>> b0 = {{2,0}, {3,1}, {3,2}};
        vector<vector<int>> b1 = {{2,1}, {3,0}};
        bottomMost = {b0, b1, b0, b1};
    } else if (c == 'o'){
        vector<vector<int>> s0 = {{2,0}, {2,1}, {3,0}, {3,1}};
        orientation = {s0, s0, s0, s0};
        blockWidth = {2, 2};
        vector<vector<int>> b0 = {{3,0}, {3,1}};
        bottomMost = {b0, b0, b0, b0};
    } else {
        vector<vector<int>> s0 = {{1,0}, {1,1}, {1,2}, {2,1}}; //Original starting position
        vector<vector<int>> s1 = {{1,0}, {0, 1}, {1,1}, {2, 1}}; //  1 Clockwise
        vector<vector<int>> s2 = {{0,1}, {1,0}, {1,1}, {1,2}}; // 2 Clockwise
        vector<vector<int>> s3 = {{0,0}, {1,0}, {2,0}, {1,1}}; // 3 Clockwise
        orientation = {s0, s1, s2, s3};

        blockWidth = {3, 2};

        vector<vector<int>> b0 = {{2,1}, {1,2}};
        vector<vector<int>> b1 = {{2,1}, {1,0}};
        vector<vector<int>> b2 = {{1,1}, {1,0}, {1,2}};
        vector<vector<int>> b3 = {{2,0}, {1,1}};
        bottomMost = {b0, b1, b2, b3};
    }
    x = 0;
    y = 0;
    i = 0;
}
char Block::getBlockType(){
    return c;
}

void Block::rotateClockWise(){
    if (i == 3) i = 0;
    else{
        ++i;
    }
}

void Block::rotateCounterClockWise(){
    if (i == 0) i = 3;
    else{
        --i;
    }
}

void Block::moveBlockRight(){
    // create a check for out of range
    // create a check for current orientation and max width
    int colAdd = 0;
    int colMargin;
    if (i == 0 || i == 2){
        colMargin = 11 - blockWidth[0];
        if (x < colMargin){
            // we've basically incremented the x (col) values by 1
            colAdd = 1;
            ++x;
        }
    }
    else{
        colMargin = 11 - blockWidth[1];
        if (x < colMargin){
            colAdd = 1;
            ++x;
        }
    }
    // change orientation vector
    for (int i = 0; i < 4; ++i){
        //orientation[i]; gives each of the 2d vectors
        for (int j = 0; j < 4; ++j){
            orientation[i][j][1] += colAdd;
        }
    }
    for (int i = 0; i < 4; ++i){
        int itlen = bottomMost[i].size();
        for (int j = 0; j < itlen; ++j){
            bottomMost[i][j][1] += colAdd;
        }
    }
}

void Block::moveBlockLeft(){
    int colSub = 0;
    if (x > 0){
        colSub = 1;
        --x;
    }
    for (int i = 0; i < 4; ++i){
        //orientation[i]; gives each of the 2d vectors
        for (int j = 0; j < 4; ++j){
            orientation[i][j][1] -= colSub;
        }
    }
    for (int i = 0; i < 4; ++i){
        int itlen = bottomMost[i].size();
        for (int j = 0; j < itlen; ++j){
            bottomMost[i][j][1] -= colSub;
        }
    }
}

void Block::moveBlockDown(){
    ++y;
    for (int i = 0; i < 4; ++i){
        //orientation[i]; gives each of the 2d vectors
        for (int j = 0; j < 4; ++j){
            orientation[i][j][0] += 1;
        }
    }
    
    for (int i = 0; i < 4; ++i){
        int itlen = bottomMost[i].size();
        for (int j = 0; j < itlen; ++j){
            bottomMost[i][j][0] += 1;
        }
    }


}

std::vector<std::vector<int>> Block::getStructure(){
    return orientation[i];
}

std::vector<std::vector<int>> Block::getNextCWOrientation(){
    if (i == 3){
        return orientation[0];
    }
    else{
        return orientation[i + 1];
    }
}

std::vector<std::vector<int>> Block::getNextCCWOrientation(){
    if (i == 0){
        return orientation[3];
    }
    else{
        return orientation[i - 1];
    }
}

/*
virtual std::vector<std::vector<int>> getbottomMost() = 0;
        virtual std::vector<std::vector<int>> getleftMost() = 0;
        virtual std::vector<std::vector<int>> getRightMost() = 0;
*/

std::vector<std::vector<int>> Block::getbottomMost(){
    return bottomMost[i];
}

std::vector<std::vector<int>> Block::getleftMost(){
    return leftMost[i];
}

std::vector<std::vector<int>> Block::getRightMost(){
    return rightMost[i];
}

int Block::getX(){
    return x;
}

int Block::getY(){
    return y;
}

int Block::blockRemoved(){
    if (orientation[i].empty()){
        return currLevel;
    }
    return -1;
}

void Block::rowCleared(int row, bool called){
    if (!called){
        vector<int> remIndex;
        for (int j = 0; j < orientation[i].size(); ++j){
            if (orientation[i][j][0] == row){
                remIndex.emplace_back(j);
            }
        }
        for (int x = 0; x < remIndex.size(); ++x){
            orientation[i].erase(orientation[i].begin() + remIndex[x]);
        }
    }

    //vector<int> ltRows;
    for (int j = 0; j < orientation[i].size(); ++j){
        if (orientation[i][j][0] < row){
            orientation[i][j][0] += 1;
        }
    }
}

void Block::setCurrLevel(size_t level){
    currLevel = level;
}

