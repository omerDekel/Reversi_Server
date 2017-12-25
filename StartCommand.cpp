//
// Created by omer on 24/12/17.
//

#include "StartCommand.h"
#include "Games.h"

void StartCommand::execute(vector<string> args, int socket,GameManager &gameManager) {
    Games game = Games(args[0]);
    game.setSocket1(socket);
    gameManager.add_game(args[0], game);
    // add to game Manager list .

}

/*StartCommand::StartCommand(int socket) {

}*/
