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
class Games {
public:
    Games(){}
    Games(string &name);
    std::vector<std::string> get_game_list() const;
    void start_game(const std::string& game_name);
    void join_game(const std::string& game_name, const int player_socket);
    std::vector<int> get_game_players(const std::string& game_name) const;
    void remove_game(const std::string& game_name);
    string getGameName();
    void addPlayer(int socket);
    int getCountClients() const;

    int getSocket1() ;

    int getSocket2() ;

private:
    void _lock_mutex();
    void _unlock_mutex();
    string gameName;
    //int countClients = 0;
/*public:
    void setCountClients(int countClients);*/

private:
    int socket1;
public:
    void setSocket1(int socket1);

    void setSocket2(int socket2);

private:
    int socket2;
    /*std::map<std::string, std::vector<int>> m_games*/;
    pthread_mutex_t m_mutex;
};


#endif //SERVER_GAME_H
