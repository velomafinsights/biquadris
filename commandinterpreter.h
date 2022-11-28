#ifndef COMMANDINTERPRETER_H
#define COMMANDINTERPRETER_H
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>

using namespace std;


class commandInterpreter{
        std::vector<std::string> core = {
            "left", "right", "down", "clockwise", "counterclockwise", "drop", "level up", "level down", "norandom", "random",
            "sequence", "I", "J", "K", "L", "S", "T", "Z", "O", "restart", "heavy", "blind", "force"
        };

        std::vector<std::string> users = {};

        std::map<std::string, std::string> userDefined;
    public:
        // performs startsWith string comparison
        bool validSubString(std::string original, std::string sub);

        // returns the corresponding command 
        std::string process(std::string given);
        int multiplier(std::string input);
        void rename(std::string toRename, std::string given);
};

#endif

