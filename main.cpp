#include <iostream>
#include "Server.h"
#include <iostream>
#include <stdlib.h>
using
namespace
std;

int main() {
    Server server(6666);
    try {
        server.start();
    }
    catch (const char *msg) {
        cout << "Cannot start server. Reason: " << msg << endl;
        exit(-1);
    }
}