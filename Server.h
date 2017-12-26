//
// Created by omer on 02/12/17.
//

#ifndef UNTITLED4_SERVER_H
#define UNTITLED4_SERVER_H


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
    int port1;
    int serverSocket1;
    //int clientSocket[2];
    /**
     * handle the players
     */
    char buf[50];

};


#endif //UNTITLED4_SERVER_H
