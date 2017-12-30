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

    void handleClient(int socket);
    /**
     * stop the server
     */
    void stop();
    int getClientSocket() const;
    /**
     * stop to accept clients to connect the server .
     */
    void stopAccept();

private:
    GameManager *gameManager;
    int port1;
    int serverSocket1;
    bool shouldStop;
    vector <pthread_t> threads;
    int clientSocket;
    char buf[50];

};


#endif //UNTITLED4_SERVER_H
