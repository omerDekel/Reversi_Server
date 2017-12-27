//
// Created by omer on 25/12/17.
//

#include <unistd.h>
#include "JoinCommand.h"
JoinCommand::JoinCommand(int socket,GameManager &gameManager) {
    this->socket = socket;
    this->gameManager = gameManager;
}
void JoinCommand:: execute(vector<string> args/*, int socket,GameManager &gameManager*/) {
    std::cout <<"joined"<<std::endl;
    gameManager.join_game(args[0], socket);
    //close(socket);
}