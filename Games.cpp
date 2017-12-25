//
// Created by dana on 12/15/17.
//

#include "Games.h"

Games::Games(string &name) {
    this->gameName = name;
}
/*void Games:: addPlayer(int socket) {
    this->
}*/
string &Games::getGameName() const {
    return gameName;
}

int Games::getCountClients() const {
    return countClients;
}

int Games::getSocket1() const {
    return socket1;
}

int Games::getSocket2() const {
    return socket2;
}

void Games::setCountClients(int countClients) {
    Games::countClients = countClients;
}

void Games::setSocket1(int socket1) {
    Games::socket1 = socket1;
    countClients++;
}

void Games::setSocket2(int socket2) {
    Games::socket2 = socket2;
    countClients++;
}
