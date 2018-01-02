//
// Created by omer on 24/12/17.
//

#ifndef UNTITLED6_STARTCOMMAND_H
#define UNTITLED6_STARTCOMMAND_H

#include "Command.h"
#include <iostream>

class StartCommand : public Command {
public:
    /**
     * execute the command.
     * @param args the args
     */
    virtual void execute(vector<string> args/*, int socket,GameManager &gameManager*/);

    /**
     * constructor
     * @param socket the socket.
     * @param gameManager the game manager.
     */
    StartCommand(int socket , GameManager *gameManager);

private:
    int socket;
    GameManager *gameManager;
};

#endif //UNTITLED6_STARTCOMMAND_H
