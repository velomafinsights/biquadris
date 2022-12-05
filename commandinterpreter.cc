#include "commandinterpreter.h"
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

bool commandInterpreter::validSubString(std::string original, std::string sub){
    if (original.find(sub) == 0){
        return true;
    }
    else{
        return false;
    }
}

std::string commandInterpreter::process(std::string given){
    std::string given2;
    size_t k = 0;
    for(k; k < given.length(); ++k){
        if(given[k]>='0' && given[k]<='9'){
        } else {
            break;
        }
    }
    given2 = given.substr(k);
    int validOptions = 0;
    string validCommand;
    for (vector<std::string>::iterator it = core.begin(); it != core.end(); ++it){
        if (validSubString(*it, given2)){
            ++validOptions;
            validCommand = *it;
        }
    }
    for (vector<std::string>::iterator it1 = users.begin(); it1 != users.end(); ++it1){
        if (validSubString(*it1, given2)){
            ++validOptions;
            validCommand = userDefined[*it1];
        }
    }
    if(validOptions == 1){
        return validCommand;
    }
    return "Invalid Output";
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
    size_t idx = NULL;
    for(size_t i =0; i<users.size(); i++){
        if(users[i] == given){
            idx = i;
            break;
        }
    }
    if(idx != NULL){
        users.erase(users.begin()+idx);
    }
    userDefined[given] = toRename;
    users.emplace_back(given);
}


