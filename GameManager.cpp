//
// Created by omer on 24/12/17.
//

#include <iostream>
#include <unistd.h>
#include <cstring>
#include "GameManager.h"
using namespace std;
void GameManager::join_game(std::string &game_name , const int player_socket) {

    //int numOfClients;
    //this->m_games.insert(game_name,);
    if (m_games.count(game_name)) {
        m_games[game_name].setSocket2(player_socket);
        /*numOfClients = m_games[game_name].getCountClients();
        //m_games[game_name].setCountClients(numOfClients++);
        if (numOfClients == 2) {
            //thread handleplayers of the last projects .
        }*/
        play_game(m_games[game_name].getSocket1(), m_games[game_name].getSocket2());
        close(m_games[game_name].getSocket1());
        close(m_games[game_name].getSocket2());
    }
}
void GameManager::add_game(std::string &game_name , Games g) {
    if (!m_games.count(game_name)) {
        this->m_games.insert(std::pair<std::string , Games>(game_name , g));
    }
}
// Handle requests from a specific client
void GameManager::play_game(int socket1, int socket2) {
    int clientSocket[2];

    clientSocket[0] = socket1;
    clientSocket[1] = socket2;
    for (int current_player = 0;; current_player = (current_player + 1) % 2) {
        std::cout << "Reading from player #" << current_player << std::endl;
        int other_player = (current_player + 1) % 2;
        char buf[8];
        int n = read(clientSocket[current_player] , buf , sizeof(buf));
        if (n == -1) {
            cout << "Error" << endl;
            return;
        }
        // if one of the players disconnected .
        if (n == 0) {
            cout << "player disconnected"<< endl;
            return;
        }
        std::cout << "Got " << n << " bytes" << std::endl;
        std::cout << buf << std::endl;

        if (strcmp(buf , "END") == 0) {
            return;
        }
        if (strcmp(buf , "NoMove") == 0) {
            continue;
        }

        n = write(clientSocket[other_player] , buf , n);
        if (n == -1) {
            cout << "Error" << endl;
            return;
        }
        //if one of the players disconnected .
        if (n == 0) {
            cout << "player disconnected"<< endl;
            return;
        }
    }

}
