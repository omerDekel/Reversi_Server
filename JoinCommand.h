//
// Created by omer on 25/12/17.
//

#ifndef UNTITLED6_JOINCOMMAND_H
#define UNTITLED6_JOINCOMMAND_H

#include "Command.h"
#include <iostream>

using namespace std;

class JoinCommand : public Command {
public:
    /**
     * execute the jion command.
     * @param args the args.
     */
    virtual void execute(vector<string> args/*, int socket,GameManager &gameManager*/);

    /**
     * constructor.
     * @param socket the socket.
     * @param gameManager the game manager.
     */
    JoinCommand(int socket , GameManager *gameManager);

private:
    int socket;
    GameManager *gameManager;
};


#endif //UNTITLED6_JOINCOMMAND_H
