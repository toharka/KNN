//
// Created by lioze on 1/22/2023.
//

#include "SocketIO.h"
#include "Globals.h"
#include "DataAdapter.h"
#include "Knn.h"
#include "StringUtils.h"
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include <iostream>
#include <cstring>
#include <utility>
#include "Globals.h"
using namespace std;
string SocketIO::read(){
    char clientMessageArguments[4096] = "";
    int expected_data_len = sizeof(clientMessageArguments);


    int read_bytes = recv(this->clientSocketID, clientMessageArguments, expected_data_len, 0);
    if (read_bytes == 0) {
        return Globals::STATUC_CODE_FAILURE;
        perror("error reading from client");

    }else if (read_bytes < 0) {
        return Globals::STATUC_CODE_FAILURE;
        perror("error reading from client");

    }
    return clientMessageArguments;
}

void SocketIO::write(string data){
    responseQueue.push(data);
}
void SocketIO::sendData(){
    string result = "";
    while(!responseQueue.empty()){
        result.append(responseQueue.front().append("\n"));
        responseQueue.pop();
    }
    char message[4092];
    strcpy(message,result.c_str());
    int sent_bytes = send(this->clientSocketID, message, 4092, 0);
    if (sent_bytes < 0) {
        perror("error sending to client");
    }
}

void SocketIO::waitForSuccess() {
    string data = read();
    while(Globals::STATUS_CODE_SUCCESS!=data){

    }
}

void SocketIO::closeSocket() {
    close(this->clientSocketID);
}
