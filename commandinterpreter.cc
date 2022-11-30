#include "commandinterpreter.h"
#include <string>
#include <sstream>
#include <vector>
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
    //given2 will be the modified string after checking for multi
    std::string given2;
    size_t k = 0;
    for(k; k < given.length(); ++k){
        if(given[k]>='0' && given[k]<='9'){
        } else {
            break;
        }
    }

    given2 = given.substr(k);
    // number of matches between given and vector<string> core
    int validOptions = 0;
    string validCommand;
    for (vector<std::string>::iterator it = core.begin(); it != core.end(); ++it){
        if (validSubString(*it, given2)){
            ++validOptions;
            validCommand = *it;
        }
    }

    //number of matches between given and vector<string> user defined
    for (vector<std::string>::iterator it1 = users.begin(); it1 != users.end(); ++it1){
        if (validSubString(*it1, given2)){
            ++validOptions;
            validCommand = userDefined[*it1];
        }
    }
    
    if(validOptions == 1){
        return validCommand;
    } else {
        return "Invalid Output";
    }
    //return validCommand;
}

int commandInterpreter::multiplier(std::string given){
    std::string multi = "";
    std::stringstream ss;
    size_t toRet;
    for(size_t k = 0; k < given.length(); ++k){
        if(given[k]>='0' && given[k]<='9'){
            multi+=given[k];
        } else {
            break;
        }
    }

    if(multi.length() == 0){
        return 1;
    } else {
        ss << multi;
        ss >> toRet;
        return toRet;
    }
}

void commandInterpreter::rename(std::string toRename, std::string given){
    //vector<std::string>::iterator it;
    //it = remove(users.begin(), users.end(), given);
    userDefined[given] = toRename;
    users.emplace_back(given);
}



