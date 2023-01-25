//
// Created by lioze on 1/15/2023.
//



#ifndef SERVERMILESTONEEX3_DEFAULTIO_H
#define SERVERMILESTONEEX3_DEFAULTIO_H

#include <string>

#include <iostream>
#include <queue>
using namespace std;

class DefaultIO {
protected:
    queue<string> responseQueue;

public:

      virtual string read() = 0;
      virtual void write(string str) = 0;
      virtual void sendData() = 0;
      virtual void waitForSuccess() = 0;
    virtual void closeSocket() = 0;

};


#endif //SERVERMILESTONEEX3_DEFAULTIO_H
