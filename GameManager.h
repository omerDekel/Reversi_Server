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
    /**
     * getting game list
     * @return the list
     */
    std::vector<std::string> get_game_list() const;

    /**
     * join the game
     * @param game_name the game name.
     * @param player_socket the player socket.
     */
    void join_game(std::string &game_name , int &player_socket);

    /**
     * add the game.
     * @param game_name the game name.
     * @param socket the socket.
     */
    void add_game(std::string &game_name , int socket);

    /**
     * remove the game
     * @param game_name  the game name.
     */
    void remove_game(const std::string &game_name);

    /**
     * play the game.
     * @param g the game.
     */
    void play_game(Game g);

    /**
     * getting the games
     * @return  the map of the game.
     */
    map<string , Game *> getM_games();

    /**
     * getting mutex.
     * @return mutex.
     */
    pthread_mutex_t * getM_mutex() ;

private:
    map<string , Game *> m_games;
    pthread_mutex_t m_mutex;
};


#endif //UNTITLED6_GAMEMANAGER_H
