#include "piece.h"
#include <string>

piece::piece(size_t x, size_t y, char c, bool filled): x{x}, y{y}, c{c}, filled{filled} {}
bool piece::getFiled(){
    return filled;
}
void piece::setFilled(bool toSet){
    filled = toSet;
}

char piece::getC(){
    return c;
}
void piece::setC(char toSet){
    c = toSet;
}


size_t piece::getX(){
    return x;
}
size_t piece::getY(){
    return y;
}