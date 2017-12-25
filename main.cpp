#include <iostream>
#include "Server.h"
#include <stdlib.h>
#include <fstream>

#include "Games.h"

using
namespace
std;

Games g_game_list;

int handle_single_player(void* player_socket)
{
    // got a list_games command
    std::vector<std::string> games = g_game_list.get_game_list();
    // turn games int blabla buffer
    write(player_socket, blabla, sizeof(blabla));

}


int main() {
    ifstream inFile;
    int port;
    inFile.open("/home/dana/CLionProjects/server/settings");
    inFile>> port;
    cout<<port;
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
