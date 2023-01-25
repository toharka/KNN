//
// Created by lioze on 1/22/2023.
//

#include "serverFinal.h"
#include "DataAdapter.h"
#include "Knn.h"
#include "StringUtils.h"
#include "StandardIO.h"
#include "service.h"
#include "SocketIO.h"
#include "Globals.h"
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include <iostream>
#include <cstring>
#include <utility>
#include <string>

using namespace std;


int main(int argc, char **argv){

if (argc < 2) {
        cout << "some of the arguments are missing" << endl;
        return 0;
        cout<<"fss";
    }

    int port_no = stoi(argv[1]);
    serverFinal::runServer(port_no);

}

// void serverFinal::run() {
//     int server_port = Globals::SERVER_PORT;
//     runServer(server_port);
// }


void serverFinal::runServer(int server_port) {
    /* It creates a socket and binds it to the port. */
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("error creating socket");
    }
    struct sockaddr_in sin;
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = INADDR_ANY;
    sin.sin_port = htons(server_port);
    if (bind(sock, (struct sockaddr *) &sin, sizeof(sin)) < 0) {
        perror("error binding socket");
    }
    if (listen(sock, 100) < 0) {
        perror("error listening to a socket");
    }

    bool running = true;
    /* Waiting for a client to connect to the server. */
    while (running) {
        struct sockaddr_in client_sin;
        unsigned int addr_len = sizeof(client_sin);
        int client_sock = accept(sock, (struct sockaddr *) &client_sin, &addr_len);
        if (client_sock < 0) {
            perror("error accepting client");
        }
        SocketIO *socketIo = new SocketIO(client_sock);
        service *ser = new service(socketIo);
    }
    close(sock);
}