//
// Created by omer on 02/12/17.
//

#ifndef UNTITLED4_SERVER_H
#define UNTITLED4_SERVER_H

#include "stdio.h"
#include "GameManager.h"
#include <iostream>
#include <sys/types.h>
#include <vector>

using namespace std;
class Server {
public:
    /**
     * constructor
     * @param port
     */
    Server (int port);
    /**
     * destructor ;
     */
    ~Server();
    /**
     * start the server
     */
    void start();
    /**
     * stop the server
     */
    void handleClient(int socket);
    void stop();
    void handlePlayers();
    int getClientSocket() const;

private:
    GameManager *gameManager;
    int port1;
    int serverSocket1;
    //vector <pthread_t> threads;
    int clientSocket;
    /**
     * handle the players
     */
    char buf[50];

};


#endif //UNTITLED4_SERVER_H
