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
    /**
     * constructor.
     */
    Game() {}

    /**
     * constructor
     * @param name the name .
     * @param socket the cocket.
     */
    Game(string &name , int socket);

    /**
     * get game player.
     * @param game_name the game player.
     * @return vector of the games.
     */
    std::vector<int> get_game_players(const std::string &game_name) const;

    /**
     * getting the game name
     * @return the game name
     */
    string getGameName();

    /**
     * adding player
     * @param socket the socket.
     */
    void addPlayer(int socket);

    /**
     * getting count clients.
     * @return the count clients.
     */
    int getCountClients() const;

    /**
     * getting socket1
     * @return the socket of the player
     */
    int getSocket1() const;

    /**
     * getting socket2
     * @return the socket of the player
     */
    int getSocket2() const;

    /**
     * setting socket1
     * @param socket1 the socket
     */
    void setSocket1(int socket1);

    /**
     * setting socket2
     * @param socket2 the socket
     */
    void setSocket2(int socket2);
    /*std::map<std::string, std::vector<int>> m_games*/;
private:
    string gameName;
    int socket1;
    int socket2;
    int countClients;
};


#endif //SERVER_GAME_H
