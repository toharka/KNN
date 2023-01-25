//
// Created by lioze on 1/21/2023.
//

#ifndef SERVERMILESTONEEX3_COMMANDDOWNLOADRESULTS_H
#define SERVERMILESTONEEX3_COMMANDDOWNLOADRESULTS_H


#include "Command.h"
#include "Settings.h"

class CommandDownloadResults:public Command {
public:
    CommandDownloadResults(DefaultIO *defaultIo,Settings *settings): Command(defaultIo,settings) {
        this->description = "5. download results";
    }
    void execute();
};

#endif //SERVERMILESTONEEX3_COMMANDDOWNLOADRESULTS_H
