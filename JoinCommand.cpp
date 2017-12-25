//
// Created by omer on 25/12/17.
//

#include "JoinCommand.h"
void JoinCommand:: execute(vector<string> args, int socket,GameManager &gameManager) {
    gameManager.join_game(args[0], socket);
}