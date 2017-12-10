#include <iostream>
#include "Server.h"
#include <stdlib.h>
#include <fstream>

using
namespace
std;

int main() {
    ifstream inFile;
    int port;
    inFile.open("settings");
    inFile>> port;
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