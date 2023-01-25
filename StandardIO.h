//
// Created by lioze on 1/15/2023.
//


#ifndef SERVERMILESTONEEX3_STANDARDIO_H
#define SERVERMILESTONEEX3_STANDARDIO_H
#include "DefaultIO.h"
class StandardIO : public DefaultIO{
public:
    string read() override ;
    void write(string data) override;
    void sendData() override;
    void waitForSuccess() override;
     void closeSocket();

};


#endif //SERVERMILESTONEEX3_STANDARDIO_H
