//
// Created by dana on 12/15/17.
//

#ifndef SERVER_GAME_H
#define SERVER_GAME_H

#include <string>
#include <map>
#include <vector>
#include <pthread.h>
using namespace std;
class Game {
public:
    Game(){}
    Game(string &name, int socket);
    std::vector<int> get_game_players(const std::string& game_name) const;
    string getGameName();
    void addPlayer(int socket);
    int getCountClients() const;
    int getSocket1() const ;
    int getSocket2() const ;
    void setSocket1(int socket1);
    void setSocket2(int socket2);
    /*std::map<std::string, std::vector<int>> m_games*/;
private:
    string gameName;
    int socket1;
    int socket2;
    int countClients ;
};


#endif //SERVER_GAME_H
