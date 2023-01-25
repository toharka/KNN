

#include "CommandDownloadResults.h"
#include <fstream>
#include "Globals.h"
/**
 * It sends the classified data to the client
 * @returns The results of the classification.
 */

void CommandDownloadResults::execute() {
    int length = this->settings->getClassifiedTest().size();
    vector<std::string> classified = settings->getClassifiedTest();

    if (settings->getClassifiedData()->empty()) {
        defaultIO->write(Globals::PLEASE_UPLOAD_DATA);
        return;
    }
    if (length == 0) {
        defaultIO->write(Globals::PLEASE_CLASSIFY_DATA);
        return;
    }

    defaultIO->write(Globals::DISPLAY_RESULT_UN_SYNCRONIZED);
    defaultIO->sendData();
    defaultIO->read();

    for (size_t i = 0; i < length; i++) {
        int k = i + 1;
        defaultIO->write(to_string(k).append("\t").append(classified.at(i).substr(0,classified.at(i).size() - 1)));
        defaultIO->sendData();
        defaultIO->read();

    }
    defaultIO->write(Globals::DISPLAY_RESULT_END);
    defaultIO->sendData();
    defaultIO->read();




}