#ifndef COMMANDINTERPRETER_H
#define COMMANDINTERPRETER_H
#include <vector>
#include <string>
#include <iostream>
#include <sstream>

using namespace std;


class commandInterpreter{
        std::vector<std::string> core = {
            "left", "right", "down", "clockwise", "counterclockwise", "drop", "level up", "level down", "norandom", "random",
            "sequence", "I", "J", "K", "L", "S", "T", "Z", "O", "restart"
        };
    public:
        // performs startsWith string comparison
        bool validSubString(std::string original, std::string sub);

        // returns the corresponding command 
        std::string process(std::string given);
        int multiplier(std::string input);
        std::string rename(std::string toRename, std::string given);
};

#endif

