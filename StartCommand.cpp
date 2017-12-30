//
// Created by omer on 24/12/17.
//

#include "StartCommand.h"

StartCommand::StartCommand(int socket1, GameManager *gameManager1) {
    this->gameManager = gameManager1;
    this->socket = socket1;
}

void StartCommand::execute(vector<string> args) {
    gameManager->add_game(args[0], socket);

}

