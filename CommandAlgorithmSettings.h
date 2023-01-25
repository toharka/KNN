//
// Created by lioze on 1/21/2023.
//

#ifndef SERVERMILESTONEEX3_COMMANDALGORITHMSETTINGS_H
#define SERVERMILESTONEEX3_COMMANDALGORITHMSETTINGS_H

#include "Command.h"
#include "Settings.h"

class CommandAlgorithmSettings:public Command {
public:
    CommandAlgorithmSettings(DefaultIO *defaultIO,Settings *settings): Command(defaultIO,settings) {
         this->description = "2. algorithm settings";
    }
    void execute();
};


#endif //SERVERMILESTONEEX3_COMMANDALGORITHMSETTINGS_H
