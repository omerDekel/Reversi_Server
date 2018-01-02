//
// Created by omer on 24/12/17.
//

#include <iostream>
#include <unistd.h>
#include <cstring>
#include "GameManager.h"

using namespace std;

void GameManager::join_game(std::string &game_name , int &player_socket) {
    if (m_games.count(game_name)) {
        if (m_games[game_name]->getCountClients() == 1) {
            // locking the access to the map.
            pthread_mutex_lock(&m_mutex);
            m_games[game_name]->setSocket2(player_socket);
            pthread_mutex_unlock(&m_mutex);
            std::cout << "play" << std::endl;
            play_game(*m_games[game_name]);
            close(m_games[game_name]->getSocket1());
            close(m_games[game_name]->getSocket2());
            // unlock the acces to the map .
            pthread_mutex_lock(&m_mutex);
            //deleting the game from the map .
            delete m_games[game_name];
            m_games.erase(game_name);
            pthread_mutex_unlock(&m_mutex);
        }
    } else {
        int n = write(player_socket , "-1" , sizeof("-1"));
        if (n == -1) {
            throw "couldnt write";
        }
    }
}

void GameManager::add_game(std::string &game_name , int socket) {
    if (!m_games.count(game_name)) {
        Game *game = new Game(game_name , socket);
        // locking the acces to the map.
        pthread_mutex_lock(&m_mutex);
        this->m_games[game_name] = game;
        // unlock the acces to the map .
        pthread_mutex_unlock(&m_mutex);
        std::cout << (m_games[game_name])->getGameName() << std::endl;
    } else {
        //sending error code to the client
        int n = write(socket , "-1" , sizeof("-1"));
        if (n == -1) {
            throw "couldnt write";
        }

    }
}

void GameManager::play_game(Game g) {
    int clientSocket[2];
    clientSocket[0] = g.getSocket1();
    clientSocket[1] = g.getSocket2();
    write(clientSocket[0] , "1" , sizeof("1"));
    write(clientSocket[1] , "2" , sizeof("2"));
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
            cout << "player disconnected" << endl;
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
            cout << "player disconnected" << endl;
            return;
        }
    }

}

map<string , Game *> GameManager::getM_games() {
    return m_games;
}

pthread_mutex_t *GameManager::getM_mutex() {
    return &m_mutex;
}
