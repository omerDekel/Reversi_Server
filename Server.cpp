//
// Created by omer on 02/12/17.
//

#include "Server.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include <iostream>
#include <fstream>

using namespace std;

Server::Server(int port) : port1(port) , serverSocket1(0) {
    cout << "Server" << endl;
}

void Server::start() {
    int count = 0;
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
    while (true) {
        cout << "Waiting for client connections..." << endl;

// Accept a new client connection  תהליכונים
        clientSocket[count] = accept(serverSocket1 , (struct sockaddr *) &clientAddress , &clientAddressLen);
        cout << "client socket is" << clientSocket[count] << endl;
        if (clientSocket[count] == -1) {
            throw "Error on accept";
        }
        count++;
        //if there are two clients .
        if (count > 0 && (count % 2 == 0)) {
            write(clientSocket[0] , "1" , sizeof("1"));
            write(clientSocket[1] , "2" , sizeof("2"));
            handlePlayers();
            // Close communication with the client
            close(clientSocket[0]);
            close(clientSocket[1]);
        }
    }
}

// Handle requests from a specific client
void Server::handlePlayers() {
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

}

void Server::stop() {
    close(serverSocket1);
}