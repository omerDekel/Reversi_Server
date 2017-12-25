//
// Created by omer on 25/12/17.
//

#ifndef UNTITLED6_JOINCOMMAND_H
#define UNTITLED6_JOINCOMMAND_H

#include "Command.h"
#include <iostream>
using namespace std;
class JoinCommand :  public Command {
    virtual void execute(vector<string> args, int socket,GameManager &gameManager);
    virtual ~Command() {}
private:
    int socket;
};


#endif //UNTITLED6_JOINCOMMAND_H
