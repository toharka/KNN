//
// Created by lioze on 1/19/2023.
//

#ifndef SERVERMILESTONEEX3_CLI_H
#define SERVERMILESTONEEX3_CLI_H

#include <queue>
#include <vector>
#include "Command.h"
#include "Settings.h"

using namespace std;
class CLI {
private:
    queue<int> commandsQueue;
    vector<Command*> commandList;
    void printCommands();
    bool isRunning = false;
    Command* getCommand(string option);
    Settings *settings;
    DefaultIO *defaultIO;
public:
    CLI(vector<Command*> &commandList, DefaultIO *defaultIo, Settings *settings)
            : commandList(commandList), defaultIO(defaultIo), settings(settings){

};
    void start();
};


#endif //SERVERMILESTONEEX3_CLI_H
