//
// Created by omer on 24/12/17.
//

#include "GameManager.h"
void GameManager::join_game(std::string &game_name , const int player_socket) {

    int numOfClients;
    //this->m_games.insert(game_name,);
    if (m_games.count(game_name)) {
        m_games[game_name].setSocket2(player_socket);
        numOfClients = m_games[game_name].getCountClients();
        //m_games[game_name].setCountClients(numOfClients++);
        if (numOfClients == 2) {
            //thread handleplayers of the last projects .
        }
    }
}
void GameManager::add_game(std::string &game_name , Games g) {
    if (!m_games.count(game_name)) {
        this->m_games.insert(std::pair<std::string , Games>(game_name , g));
    }
}