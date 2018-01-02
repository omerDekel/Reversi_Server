#include <iostream>
#include "Server.h"
#include <stdlib.h>
#include <fstream>

#include "Game.h"

using namespace std;


int main() {
    ifstream inFile;
    int port;
    inFile.open("/home/omer/CLionProjects/untitled6/settings");
    inFile >> port;
    cout << port;
    Server server(port);
    inFile.close();
    try {
        server.start();
    }
    catch (const char *msg) {
        cout << "Cannot start server. Reason: " << msg << endl;
        exit(-1);
    }
    server.stop();
}
