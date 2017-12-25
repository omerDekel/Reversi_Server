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

class GameManager {
public:

    std::vector<std::string> get_game_list() const;
    //void start_game(const std::string& game_name);
    void join_game(std::string& game_name, const int player_socket);
    void add_game(std::string& game_name, Games);
    //std::vector<int> get_game_players(const std::string& game_name) const;
    void remove_game(const std::string& game_name);

private:
    void _lock_mutex();
    void _unlock_mutex();

    std::map<std::string, /*std::vector<int>*/Games> m_games;
    pthread_mutex_t m_mutex;

};


#endif //UNTITLED6_GAMEMANAGER_H
