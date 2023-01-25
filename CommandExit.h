//
// Created by lioze on 1/21/2023.
//

#ifndef SERVERMILESTONEEX3_COMMANDEXIT_H
#define SERVERMILESTONEEX3_COMMANDEXIT_H



#include "Command.h"
#include "Settings.h"
#include "Globals.h"
class CommandExit:public Command {
public:
    CommandExit(DefaultIO *defaultIo,Settings *settings): Command(defaultIo,settings) {
        this->description = Globals::EXIT_DESCRIPTION;
    }

    void execute();
};


#endif //SERVERMILESTONEEX3_COMMANDEXIT_H
