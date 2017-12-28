//
// Created by omer on 28/12/17.
//

#ifndef UNTITLED6_LISTCOMMAND_H
#define UNTITLED6_LISTCOMMAND_H

#include "Command.h"
#include <iostream>

class ListCommand: public Command {
public:
    ListCommand(int socket, GameManager *gameManager);
    virtual void execute(vector<string> args/*, int socket,GameManager &gameManager*/);

private:
    int socket;
    GameManager *gameManager;
};


#endif //UNTITLED6_LISTCOMMAND_H
