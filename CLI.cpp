//
// Created by lioze on 1/19/2023.
//

#include "CLI.h"
#include "StringUtils.h"
#include <iostream>
#include <string>
#include <vector>
#include "StringUtils.h"
#include "CommandNotExists.h"
#include "CommandExit.h"
#include<sstream>
#include <cmath>
#include <iomanip>
#include <limits>
#include <map>
#include "Globals.h"

using namespace std;

void CLI::start() {
    isRunning = true;
    while(isRunning){
        printCommands();
        string option = this->defaultIO->read();
        Command* c = getCommand(option);
        if(c->getDescription().compare(Globals::EXIT_OPTION)==0){
            defaultIO->write(Globals::EXIT_OPTION);
            defaultIO->sendData();
            break;
        }

        c->execute();
        if(c->getDescription().compare(Globals::EXIT_DESCRIPTION)==0){
            break;
        }
        option = "";
    }
}



void CLI::printCommands() {
    for(int i = 0; i < this->commandList.size(); i++){
        commandList.at(i)->getDefaultIO()->write( this->commandList.at(i)->getDescription());
    }
    this->defaultIO->sendData();
}

Command* CLI::getCommand(string optionStr) {
    if(StringUtils::isNumber(optionStr)){
        int option = stoi(optionStr);
        if(option == 8){
            CommandExit *exitCommand = new CommandExit(defaultIO,settings);
            return exitCommand;
        }
        option--;
        if(option >= 0 && option <  this->commandList.size()){
            return this->commandList.at(option);
        }
    }
    CommandNotExists * command = new CommandNotExists(defaultIO,settings);
    return command;

}




