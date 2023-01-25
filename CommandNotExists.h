//
// Created by lioze on 1/21/2023.
//

#ifndef SERVERMILESTONEEX3_COMMANDNOTEXISTS_H
#define SERVERMILESTONEEX3_COMMANDNOTEXISTS_H


#include "Command.h"
#include "DefaultIO.h"
#include <string>
#include "Settings.h"

const string COMMAND_NOT_EXISTS = "command_not_exists";
class CommandNotExists:public Command{
public:
    CommandNotExists(DefaultIO *defaultIo,Settings *settings): Command(defaultIo,settings) {
            this->description = COMMAND_NOT_EXISTS;
    }

    void execute();
};



#endif //SERVERMILESTONEEX3_COMMANDNOTEXISTS_H
