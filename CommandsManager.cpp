//
// Created by omer on 25/12/17.
//

#include "CommandsManager.h"
#include "StartCommand.h"
#include "JoinCommand.h"

CommandsManager::CommandsManager() {
    commandsMap["start"] = new StartCommand();
    //delete
    commandsMap["join"] = new JoinCommand();

}
void CommandsManager::executeCommand(string command , vector<string> args, int socket,GameManager &gameManager) {
    Command *commandObj = commandsMap [command];
    commandObj->execute( args, socket, gameManager);

}

CommandsManager::~CommandsManager() {
    map<string , Command *>::iterator it;
    for (it = commandsMap.begin(); it != commandsMap.end(); it++) {
        delete it->second;
    }
}