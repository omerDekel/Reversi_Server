//
// Created by dana on 12/15/17.
//

#ifndef SERVER_GAMESLIST_H
#define SERVER_GAMESLIST_H

#include <string>
#include <map>
#include <vector>
#include <pthread.h>

class GamesList {
public:

    std::vector<std::string> get_game_list() const;
    void start_game(const std::string& game_name);
    void join_game(const std::string& game_name, const int player_socket);
    std::vector<int> get_game_players(const std::string& game_name) const;
    void remove_game(const std::string& game_name);

private:
    void _lock_mutex();
    void _unlock_mutex();

    std::map<std::string, std::vector<int>> m_games;
    pthread_mutex_t m_mutex;
};


#endif //SERVER_GAMESLIST_H
