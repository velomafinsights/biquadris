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
            "left", "right", "down", "clockwise", "counterclockwise", "drop", "levelup", "leveldown", "norandom", "random",
            "sequence", "I", "J", "K", "L", "S", "T", "Z", "O", "restart", "heavy", "blind", "force", "switch", "rename"
        };

        std::vector<std::string> users = {};

        std::map<std::string, std::string> userDefined;
    public:
        // validSubString returns true if sub is a beginning substring of original
        // ex. validSubString(left, le) == 1
        bool validSubString(std::string original, std::string sub);

        // process takes in a command such as '3lef' and processes it as 'left'
        std::string process(std::string given);

        // multiplier returns the number of times a command is called (i.e. 3lef returns 3)
        int multiplier(std::string input);

        // renames toRename command if it exists in std::vector<std::string> core
        void rename(std::string toRename, std::string given);
};

#endif

