//
// Created by lioze on 1/21/2023.
//

#ifndef SERVERMILESTONEEX3_COMMANDUPLOADUNCLASIFIED_H
#define SERVERMILESTONEEX3_COMMANDUPLOADUNCLASIFIED_H


#include "Command.h"
#include "Settings.h"

class CommandUploadUnClasified:public Command {
public:
    CommandUploadUnClasified(DefaultIO *defaultIo,Settings *settings): Command(defaultIo,settings) {
        this->description = "1. upload an unclassified csv data file";
    }

    void execute();
};


#endif //SERVERMILESTONEEX3_COMMANDUPLOADUNCLASIFIED_H
