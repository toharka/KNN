//
// Created by lioze on 1/21/2023.
//

#ifndef SERVERMILESTONEEX3_COMMANDDISPLAYRESULTS_H
#define SERVERMILESTONEEX3_COMMANDDISPLAYRESULTS_H


#include "Command.h"
#include "Settings.h"
class CommandDisplayResults:public Command {
public:
    CommandDisplayResults(DefaultIO *defaultIo,Settings *settings): Command(defaultIo,settings) {
        this->description = "4. display results";
    }

    void execute();
};

#endif //SERVERMILESTONEEX3_COMMANDDISPLAYRESULTS_H
