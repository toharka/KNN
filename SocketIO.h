//
// Created by lioze on 1/22/2023.
//

#ifndef SERVERMILESTONEEX3_SOCKETIO_H
#define SERVERMILESTONEEX3_SOCKETIO_H


#include "DefaultIO.h"

class SocketIO: public DefaultIO{
    int clientSocketID;
public:
    SocketIO(int clientSocketID):clientSocketID(clientSocketID){

    }
     string read() ;
     void write(string str);
     void sendData() ;
     void waitForSuccess();
     void closeSocket();
};


#endif //SERVERMILESTONEEX3_SOCKETIO_H
