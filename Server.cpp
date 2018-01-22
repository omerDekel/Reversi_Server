//
// Created by omer on 02/12/17.
//
#include "stdio.h"
#include "Server.h"
#include "GameManager.h"
#include "CommandsManager.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <boost/algorithm/string/classification.hpp>
#include <boost/algorithm/string/split.hpp>
#include <boost/foreach.hpp>

using namespace boost::algorithm;
using namespace std;

#define MAX_CONNECTED_CLIENTS 10
#define MAX_COMMAND_LEN 20
#define MAX_ARG_LEN 20
#define MAX_THREADS 5
void *stopServerThread(void *s) {
    Server *myServer = (Server *) s;
    string exit = "";
    do {
        if (exit == "exit") {
            myServer->stopAccept();
            myServer->stop();
            break;
        }
        cin >> exit;
    } while (true);
}

void *HandleClientThread(void *s) {
    Server *myServer = (Server *) s;
    myServer->handleClient(myServer->getClientSocket());
}

Server::Server(int port) : port1(port) , serverSocket1(0) , shouldStop(false),threadPool(MAX_THREADS) {
    gameManager = new GameManager();
    cout << "Server" << endl;
}

void Server::start() {
    pthread_t pthread;
// Create a socket point
    serverSocket1 = socket(AF_INET , SOCK_STREAM , 0);
    if (serverSocket1 == -1) {
        throw "Error opening socket";
    }
    // Assign a local address to the socket
    struct sockaddr_in serverAddress;
    bzero((void *) &serverAddress , sizeof(serverAddress));
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    serverAddress.sin_port = htons(port1);
    if (bind(serverSocket1 , (struct sockaddr *) &serverAddress , sizeof(serverAddress)) == -1) {
        stop();
        throw "Error on binding";
    }
// Start listening to incoming connections
    listen(serverSocket1 , MAX_CONNECTED_CLIENTS);
// Define the client socket's structures
    struct sockaddr_in clientAddress;
    socklen_t clientAddressLen = sizeof((struct sockaddr *) &clientAddress);
    int rc = pthread_create(&pthread , NULL , stopServerThread , (void *) this);
    if (rc) {
        cout << "Error: unable to create thread, " << rc << endl;
        exit(-1);
    }
    while (!shouldStop) {
        cout << "Waiting for client connections..." << endl;

// Accept a new client connection
        clientSocket = accept(serverSocket1 , (struct sockaddr *) &clientAddress , &clientAddressLen);
        cout << "client socket is" << clientSocket << endl;
        if (clientSocket == -1) {
            throw "Error on accept";
        }
        Task task(HandleClientThread ,this);
        threadPool.addTask(&task);
    }

}

void Server::handleClient(int socket) {
    CommandsManager commandsManager(socket , gameManager);
    char command[MAX_COMMAND_LEN];
    char arg[MAX_ARG_LEN];
    while (true) {
        vector<string> args;
        int n = read(socket , buf , sizeof(buf));
        if (n == -1) {
            cout << "Error" << endl;
            return;
        }
        if (n == 0) {
            break;
        }
        sscanf(buf , "%s %s" , command , arg);
        string strCom(command);
        string strArg(arg);
        args.push_back(strArg);
        commandsManager.executeCommand(strCom , args);
        if (strCom == "start" || strCom == "join") {
            break;
        }
    }
}

void Server::stopAccept() {
    this->shouldStop = true;
}

void Server::stop() {
    map<string , Game *>::iterator it;
    for (it = gameManager->getM_games().begin(); it != gameManager->getM_games().end(); it++) {
        close(it->second->getSocket1());
        if (it->second->getSocket2() != 0) {
            close(it->second->getSocket2());
        }
    }
    threadPool.terminate();
    close(serverSocket1);
    map<string , Game *>::iterator it2;
    for (it2 = gameManager->getM_games().begin(); it2 != gameManager->getM_games().end(); it2++) {
        delete it2->second;
    }
    delete gameManager;
    exit(1);
}

int Server::getClientSocket() const {
    return clientSocket;
}

Server::~Server() {
    map<string , Game *>::iterator it;
    for (it = gameManager->getM_games().begin(); it != gameManager->getM_games().end(); it++) {
        delete it->second;
    }

    delete gameManager;
}
