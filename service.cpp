//
// Created by lioze on 1/22/2023.
//

#include "service.h"
#include "CLI.h"
#include "StandardIO.h"
#include "CommandExit.h"
#include "CommandClassifyData.h"
#include "CommandDisplayResults.h"
#include "CommandAlgorithmSettings.h"
#include "CommandUploadUnClasified.h"
#include "CommandDownloadResults.h"
#include <thread>
using namespace std;
vector<Command*> getAllCommands(DefaultIO *defaultIo,Settings *settings);
service::service(SocketIO *defaultIo) {
    string distanceType = "AUC";
    Settings *settings =  new Settings(distanceType,5);
    settings->set("AUC",5);
    vector<Command*> commandList = getAllCommands(defaultIo,settings);
    CLI *cli = new CLI(commandList, defaultIo, settings);
    thread worker(&CLI::start,cli);
    worker.detach();
}



vector<Command*> getAllCommands(DefaultIO *defaultIo,Settings *settings){
    vector<Command*> commandList;
    commandList.push_back(new CommandUploadUnClasified(defaultIo,settings));
    commandList.push_back(new CommandAlgorithmSettings(defaultIo,settings));
    commandList.push_back(new CommandClassifyData(defaultIo,settings));
    commandList.push_back(new CommandDisplayResults(defaultIo,settings));
    commandList.push_back(new CommandDownloadResults(defaultIo,settings));
    commandList.push_back(new CommandExit(defaultIo,settings));
    return commandList;
}