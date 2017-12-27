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
     * constractor
     * @param port
     */
    Server (int port);
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

private:
    GameManager gameManager;
    int port1;
    int serverSocket1;
    //vector <pthread_t> threads;
    int clientSocket;
public:
    int getClientSocket() const;

private:
    /**
     * handle the players
     */
    char buf[50];

};


#endif //UNTITLED4_SERVER_H
