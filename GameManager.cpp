//
// Created by omer on 24/12/17.
//

#include <iostream>
#include <unistd.h>
#include <cstring>
#include "GameManager.h"
using namespace std;
void GameManager::join_game(std::string &game_name , int &player_socket) {
    std::cout <<"hi"<<std::endl;
    //int numOfClients;
    //this->m_games.insert(game_name,);
    std::cout<<m_games[game_name]->getGameName()<<std::endl;
    std::cout << m_games.count(game_name)<< std:: endl;
    if (m_games.count(game_name)) {
        m_games[game_name]->setSocket2(player_socket);
        /*numOfClients = m_games[game_name].getCountClients();
        //m_games[game_name].setCountClients(numOfClients++);
        if (numOfClients == 2) {
            //thread handleplayers of the last projects .
        }*/
        std::cout <<"play"<<std::endl;
        /*std::cout << m_games[game_name].getSocket1()<< std::endl;
        std::cout<< m_games[game_name].getSocket2()<< std::endl;*/
        play_game(*m_games[game_name]);
        close(m_games[game_name]->getSocket1());
        close(m_games[game_name]->getSocket2());
        delete m_games[game_name];
        m_games.erase(game_name);
    }
}
void GameManager::add_game(std::string &game_name , int socket) {
    if (!m_games.count(game_name)) {
        Games *game = new Games(game_name, socket);
        this->m_games[game_name] = game ;
        std::cout<<(m_games[game_name])->getGameName()<<std::endl;
    }
}
// Handle requests from a specific client
void GameManager::play_game(Games g) {
    std::cout <<"play    cjsajc here"<<std::endl;
    int clientSocket[2];
    /*std::cout <<socket1<< std::endl;
    std::cout <<socket2<< std:: endl;*/
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

 map<string , Games *> GameManager::getM_games() {
    return m_games;
}
