#include "l.h"

blockL::blockL(){
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

    c = 'l';
    x = 0;
    y = 0;
    i = 0;         

}
