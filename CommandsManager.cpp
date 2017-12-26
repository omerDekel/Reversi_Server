//
// Created by omer on 25/12/17.
//

#include "CommandsManager.h"
#include "StartCommand.h"
#include "JoinCommand.h"

CommandsManager::CommandsManager(int socket1,GameManager &gameManager1) {
    this->socket = socket1;
    this->gameManager = gameManager1;
    commandsMap["start"] = new StartCommand(socket,gameManager);
    //delete
    commandsMap["join"] = new JoinCommand(socket,gameManager);

}
void CommandsManager::executeCommand(string command , vector<string> args, int socket,GameManager &gameManager) {
    Command *commandObj = commandsMap [command];
    commandObj->execute(args);

}

CommandsManager::~CommandsManager() {
    map<string , Command *>::iterator it;
    for (it = commandsMap.begin(); it != commandsMap.end(); it++) {
        delete it->second;
    }
}