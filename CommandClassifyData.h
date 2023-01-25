//
// Created by lioze on 1/21/2023.
//

#ifndef SERVERMILESTONEEX3_COMMANDCLASSIFYDATA_H
#define SERVERMILESTONEEX3_COMMANDCLASSIFYDATA_H

#include "Command.h"
#include "Settings.h"
#include "Settings.h"
#include "Command.h"
#include "Globals.h"
#include <vector>
#include <tuple>
#include "Knn.h"
class CommandClassifyData:public Command {
public:
    CommandClassifyData(DefaultIO *defaultIO,Settings *settings): Command(defaultIO,settings) {
        this->description = Globals::CLASSIFY_DATA_DESCRIPTION;
    }

    void execute();
};
#endif //SERVERMILESTONEEX3_COMMANDCLASSIFYDATA_H
