#include "i.h"

blockI::blockI(){
    vector<vector<int>> s0 = {{3,0}, {3,1}, {3,2}, {3,3}}; //Original starting position
    vector<vector<int>> s1 = {{0,0}, {1,0}, {2,0}, {3,0}};//Clockwise
    orientation = {s0, s1, s0, s1};
    blockWidth = {4, 1};
    
    vector<vector<int>> b0 = {{3,0}, {3,1}, {3,2}, {3,3}};
    vector<vector<int>> b1 = {{3, 0}};
    bottomMost = {b0, b1, b0, b1};
    x = 0;
    y = 0;
    i = 0;       

}
