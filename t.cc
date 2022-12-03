#include "t.h"

blockT::blockT(){
    vector<vector<int>> s0 = {{2,0}, {2,1}, {2,2}, {3,1}}; //Original starting position
    vector<vector<int>> s1 = {{2,0}, {1, 1}, {2,1}, {3, 1}}; //  1 Clockwise
    vector<vector<int>> s2 = {{1,1}, {2,0}, {2,1}, {2,2}}; // 2 Clockwise
    vector<vector<int>> s3 = {{1,0}, {2,0}, {3,0}, {2,1}}; // 3 Clockwise
    orientation = {s0, s1, s2, s3};

    blockWidth = {3, 2};

    vector<vector<int>> b0 = {{3,1}, {2,2}};
    vector<vector<int>> b1 = {{3,1}, {2,0}};
    vector<vector<int>> b2 = {{2,1}, {2,0}, {2,2}};
    vector<vector<int>> b3 = {{3,0}, {2,1}};
    bottomMost = {b0, b1, b2, b3};

    x = 0;
    y = 0;
    i = 0;       

}
