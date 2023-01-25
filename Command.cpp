//
// Created by lioze on 1/19/2023.
//

#include "Command.h"
#include "DefaultIO.h"
#include <string>



DefaultIO* Command::getDefaultIO() {
    return this->defaultIO;
}

string Command::getDescription() {
    return this->description;
}




