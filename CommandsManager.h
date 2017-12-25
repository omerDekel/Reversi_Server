//
// Created by omer on 25/12/17.
//

#ifndef UNTITLED6_COMMANDSMANEGER_H
#define UNTITLED6_COMMANDSMANEGER_H
#include <map>
#include "Command.h"


class CommandsManager {
    public:
    CommandsManager();
    ~CommandsManager();
    void executeCommand(string command, vector<string> args,int socket,GameManager &gameManager);
    private:
        map<string, Command *> commandsMap;
    };


#endif //UNTITLED6_COMMANDSMANEGER_H
