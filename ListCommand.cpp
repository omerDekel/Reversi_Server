//
// Created by omer on 28/12/17.
//

#include <unistd.h>
#include <cstring>
#include "ListCommand.h"
ListCommand::ListCommand(int socket , GameManager *gameManager) {
    this->socket = socket;
    this->gameManager = gameManager;
}
void ListCommand::execute(vector<string> args) {
    string strGames = "";
    map<string , Game *>::iterator it;
    pthread_mutex_lock(gameManager->getM_mutex());
    for (it = gameManager->getM_games().begin(); it != gameManager->getM_games().end(); it++) {
        if (it->second->getSocket2() == 0) {
            strGames = strGames+ " " +it->first;
            cout <<"add to list "<< it->first << endl;
        }
    }
    pthread_mutex_unlock(gameManager->getM_mutex());
    cout << strGames<< endl;
    int n = write(socket, strGames.c_str(), strGames.size());
    if (n == -1) {
        throw "Error sending list of games";
    }
    if (n == 0) {
        throw "could not send list of games";
    }
}
