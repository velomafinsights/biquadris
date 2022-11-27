#ifndef COMMANDINTERPRETER_H
#define COMMANDINTERPRETER_H
#include <vector>
#include <string>
#include <iostream>
#include <sstream>

class commandInterpreter{
    private:
        std::vector<std::string> core = {
            "left", "right", "down", "clockwise", "counterclockwise", "drop", "level up", "level down", "norandom", "random",
            "sequence", "I", "J", "K", "L", "S", "T", "Z", "O", "restart"
        };
    public:
        bool findMatch(std::string given, std:vector commands);
        std::string process(std::string input);
        int multiplier(std::string input);
        std::string rename(std::string toRename, std::string given);
}



#endif