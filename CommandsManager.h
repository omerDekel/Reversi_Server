//
// Created by omer on 25/12/17.
//

#ifndef UNTITLED6_COMMANDSMANEGER_H
#define UNTITLED6_COMMANDSMANEGER_H

#include <map>
#include "Command.h"


class CommandsManager {
public:
    /**
     * constructor
     * @param socket the socket
     * @param gameManager the game maneger
     */
    CommandsManager(int socket , GameManager *gameManager);

    /**
     * distractor.
     */
    ~CommandsManager();

    /**
     * execute of the command maneger
     * @param command the command
     * @param args the args
     */
    void executeCommand(string command , vector<string> args);

private:
    map<string , Command *> commandsMap;
    int socket;
};


#endif //UNTITLED6_COMMANDSMANEGER_H
