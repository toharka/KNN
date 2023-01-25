//
// Created by lioze on 1/19/2023.
//

#ifndef SERVERMILESTONEEX3_COMMAND_H
#define SERVERMILESTONEEX3_COMMAND_H


#include "DefaultIO.h"
#include "Settings.h"
#include <string>
using namespace std;
class Command {
protected:
    string description;
    DefaultIO *defaultIO;
    Settings *settings;
public:
    Command(DefaultIO *defaultIO,Settings *settings) : defaultIO(defaultIO),settings(settings){

    };

     string getDescription();
     DefaultIO* getDefaultIO();
    virtual void execute() = 0;

};


#endif //SERVERMILESTONEEX3_COMMAND_H




