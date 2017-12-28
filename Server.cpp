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
using namespace boost ::algorithm;
using namespace std;

/*void *ExcuteThread (int socket) {

}*/
void *HandleClientThread(void *s) {
    Server *myServer = (Server *)s;
    myServer->handleClient(myServer->getClientSocket());
}

Server::Server(int port) : port1(port) , serverSocket1(0) {
    gameManager = new GameManager();
    cout << "Server" << endl;
}

void Server::start() {
    /*CommandsManager commandsManager;
    GameManager gameManager;*/
    vector<pthread_t> threads;
    pthread_t thread;
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
    listen(serverSocket1 , 2);
// Define the client socket's structures
    struct sockaddr_in clientAddress;
    socklen_t clientAddressLen = sizeof((struct sockaddr*) &clientAddress);
    //pthread_t threads[100];
//thread
    while (true) {
        cout << "Waiting for client connections..." << endl;

// Accept a new client connection
        clientSocket = accept(serverSocket1 , (struct sockaddr *) &clientAddress , &clientAddressLen);
        cout << "client socket is" << clientSocket << endl;
        if (clientSocket == -1) {
            throw "Error on accept";
        }

        int rc = pthread_create(&thread, NULL, HandleClientThread ,this);
        if (rc) {
            cout << "Error: unable to create thread, " << rc << endl;
            exit(-1);
        }
        //handleClient(clientSocket);


        //count++;
        //if there are two clients .
        /*if (count > 0 && (count % 2 == 0)) {
            write(clientSocket[0] , "1" , sizeof("1"));
            write(clientSocket[1] , "2" , sizeof("2"));
            //handlePlayers();
            pthread_create(&threads[count/2], NULL, HandlePlayersThread, this);
            // Close communication with the client
            close(clientSocket[0]);
            close(clientSocket[1]);
        }*/
    }
}
void Server::handleClient(int socket) {
    //GameManager gameManager;
    CommandsManager commandsManager(socket,gameManager);
    char command[10];
    char arg[10];
    vector<string> v;
    vector<string> args;
    //stringstream stringstream1;
    while (true) {
        int n = read(socket, buf , sizeof(buf));
        if (n == -1) {
            cout << "Error" << endl;
            return;
        }
        sscanf(buf, "%s %s", command, arg);
        //arg = strstr(buf," ");
        //*(arg - 1) = '\0';
        string strCom(command);
        string strArg(arg);
        args.push_back(strArg);
        commandsManager.executeCommand(strCom, args);
    //std:: cout <<
    }
}
// Handle requests from a specific client
/*void Server::handlePlayers() {
    for (int current_player = 0;; current_player = (current_player + 1) % 2) {
        std::cout << "Reading from player #" << current_player << std::endl;
        int other_player = (current_player + 1) % 2;
        int n = read(clientSocket[current_player] , buf , sizeof(buf));
        if (n == -1) {
            cout << "Error" << endl;
            return;
        }
        // if one of the players disconnected .
        if (n == 0) {
            cout << "player disconnected"<< endl;
            return;
        }
        std::cout << "Got " << n << " bytes" << std::endl;
        std::cout << buf << std::endl;

        if (strcmp(buf , "END") == 0) {
            return;
        }
        if (strcmp(buf , "NoMove") == 0) {
            continue;
        }

        n = write(clientSocket[other_player] , buf , n);
        if (n == -1) {
            cout << "Error" << endl;
            return;
        }
        //if one of the players disconnected .
        if (n == 0) {
            cout << "player disconnected"<< endl;
            return;
        }
    }

}*/

void Server::stop() {
    close(serverSocket1);
}

int Server::getClientSocket() const {
    return clientSocket;
}
Server::~Server() {
    delete gameManager;
}
