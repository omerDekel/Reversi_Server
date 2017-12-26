//
// Created by omer on 24/12/17.
//

#ifndef UNTITLED6_COMMAND_H
#define UNTITLED6_COMMAND_H
#include <vector>
#include <string>
#include "GameManager.h"

using namespace std;
class Command {
public:
    virtual void execute(vector<string> args) =0;
    virtual ~Command() {}

/*private:
    int socket;*/
};


#endif //UNTITLED6_COMMAND_H
