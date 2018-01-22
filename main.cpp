#include <iostream>
#include "Server.h"
#include <stdlib.h>
#include <fstream>

#include "Game.h"

using namespace std;


int main() {
    ifstream inFile;
    int port;
    try {
        inFile.open("/home/omer/CLionProjects/untitled6/settings");
    } catch (...) {
        cout << "couldn't open the settings file"<< endl;
        exit(-1);
    }
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
