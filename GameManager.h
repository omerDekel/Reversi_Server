//
// Created by omer on 24/12/17.
//

#ifndef UNTITLED6_GAMEMANAGER_H
#define UNTITLED6_GAMEMANAGER_H

#include <string>
#include <map>
#include <vector>
#include <pthread.h>
#include "Games.h"
using namespace std;
class GameManager {
public:

    std::vector<std::string> get_game_list() const;
    //void start_game(const std::string& game_name);
    void join_game(std::string& game_name, int &player_socket);
    void add_game(std::string& game_name, int socket);
    //std::vector<int> get_game_players(const std::string& game_name) const;
    void remove_game(const std::string& game_name);
    void play_game(Games g);

private:
    void _lock_mutex();
    void _unlock_mutex();

    map<string, Games*> m_games;
public:
    map<string , Games *> getM_games() ;

private:
    pthread_mutex_t m_mutex;
    //GameManager &gameManager1;

};


#endif //UNTITLED6_GAMEMANAGER_H
