//
// Created by omer on 25/12/17.
//

#ifndef UNTITLED6_COMMANDSMANEGER_H
#define UNTITLED6_COMMANDSMANEGER_H
#include <map>
#include "Command.h"


class CommandsManager {
    public:
    CommandsManager(int socket, GameManager *gameManager);
    ~CommandsManager();
    void executeCommand(string command, vector<string> args);
    private:
    map<string, Command *> commandsMap;
    int socket;
};


#endif //UNTITLED6_COMMANDSMANEGER_H
