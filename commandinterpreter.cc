#include "commandinterpreter.h"
#include <string>
using namespace std;


// validSubString returns true if sub is a beginning substring of original
// ex. validSubString(left, le) == 1
bool commandInterpreter::validSubString(std::string original, std::string sub){
    if (original.find(sub) == 0){
        return true;
    }
    else{
        return false;
    }
/*
    for (vector<std::string>::iterator it = core.begin(); it != core.end(); ++it){
        if (*it == given){
            return true;
        }
    }
    return false;*/
}


std::string commandInterpreter::process(std::string given){

    // number of matches between given and vector<string> core
    int validOptions = 0;
    string validCommand;
    for (vector<std::string>::iterator it = core.begin(); it != core.end(); ++it){
        if (validSubString(*it, given)){
            ++validOptions;
            validCommand = *it;
        }
    }
    if(validOptions == 1){
        return validCommand;
    }
    return validCommand;
}


