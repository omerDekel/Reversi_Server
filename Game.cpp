//
// Created by dana on 12/15/17.
//

#include "Game.h"

Game::Game(string &name , int socket1) {
    this->gameName = name;
    this->socket1 = socket1;
    this->countClients = 1;
    this->socket2 = 0;
}

string Game::getGameName() {
    return gameName;
}

int Game::getCountClients() const {
    return countClients;
}

int Game::getSocket1() const {
    return socket1;
}

int Game::getSocket2() const {
    return socket2;
}

void Game::setSocket1(int socket1) {
    Game::socket1 = socket1;
    countClients = 1;
}

void Game::setSocket2(int socket2) {
    Game::socket2 = socket2;
    countClients = 2;
}
