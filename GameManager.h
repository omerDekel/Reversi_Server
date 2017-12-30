//
// Created by omer on 24/12/17.
//

#ifndef UNTITLED6_GAMEMANAGER_H
#define UNTITLED6_GAMEMANAGER_H

#include <string>
#include <map>
#include <vector>
#include <pthread.h>
#include "Game.h"
using namespace std;
class GameManager {
public:

    std::vector<std::string> get_game_list() const;
    void join_game(std::string& game_name, int &player_socket);
    void add_game(std::string& game_name, int socket);
    void remove_game(const std::string& game_name);
    void play_game(Game g);
    map<string , Game *> getM_games() ;
    ~GameManager();
private:
    map<string, Game*> m_games;
    pthread_mutex_t m_mutex;
};


#endif //UNTITLED6_GAMEMANAGER_H
