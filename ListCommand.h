//
// Created by omer on 28/12/17.
//

#ifndef UNTITLED6_LISTCOMMAND_H
#define UNTITLED6_LISTCOMMAND_H

#include "Command.h"
#include <iostream>

class ListCommand : public Command {
public:
    /**
     * constructor.
     * @param socket the socket.
     * @param gameManager the game manager.
     */
    ListCommand(int socket , GameManager *gameManager);

    /**
     * execute the list command.
     * @param args the args.
     */
    virtual void execute(vector<string> args);

private:
    int socket;
    GameManager *gameManager;
};


#endif //UNTITLED6_LISTCOMMAND_H
