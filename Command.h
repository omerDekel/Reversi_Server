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
    /**
     * execute the command
     * @param args the args
     */
    virtual void execute(vector<string> args) =0;
    /**
     * distractor.
     */
    virtual ~Command() {}
};


#endif //UNTITLED6_COMMAND_H
