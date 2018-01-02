//
// Created by omer on 25/12/17.
//

#include "CommandsManager.h"
#include "StartCommand.h"
#include "JoinCommand.h"
#include "ListCommand.h"

CommandsManager::CommandsManager(int socket1 , GameManager *gameManager) {
    this->socket = socket1;
    commandsMap["start"] = new StartCommand(socket , gameManager);
    commandsMap["join"] = new JoinCommand(socket , gameManager);
    commandsMap["list_games"] = new ListCommand(socket , gameManager);
}

void CommandsManager::executeCommand(string command , vector<string> args) {
    Command *commandObj = commandsMap[command];
    commandObj->execute(args);

}

CommandsManager::~CommandsManager() {
    map<string , Command *>::iterator it;
    for (it = commandsMap.begin(); it != commandsMap.end(); it++) {
        delete it->second;
    }
}