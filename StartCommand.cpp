//
// Created by omer on 24/12/17.
//

#include <unistd.h>
#include "StartCommand.h"

StartCommand::StartCommand(int socket1, GameManager *gameManager1) {
    this->gameManager = gameManager1;
    this->socket = socket1;
}

void StartCommand::execute(vector<string> args/*, int socket,GameManager &gameManager*/) {
    std::cout <<"here"<<std::endl;
    /*Games game = Games(args[0]);
    game.setSocket1(socket);*/

    //game.setSocket2(0);
    gameManager->add_game(args[0], socket);
    // add to game Manager list .
    //close the thread
    //close(socket);

}

