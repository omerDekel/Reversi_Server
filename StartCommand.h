//
// Created by omer on 24/12/17.
//

#ifndef UNTITLED6_STARTCOMMAND_H
#define UNTITLED6_STARTCOMMAND_H
#include "Command.h"
#include <iostream>
class StartCommand : public Command {
    //StartCommand(int socket);
    virtual void execute(vector<string> args, int socket,GameManager &gameManager);
    virtual ~Command() {}
/*private:
    int socket;*/

};
#endif //UNTITLED6_STARTCOMMAND_H
