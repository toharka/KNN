
#include "CommandUploadUnClasified.h"
#include <string>
#include <cstring>
#include "StringUtils.h"
#include "Globals.h"
using namespace std;

/**
 * This function is responsible for uploading the classified and unclassified data from the client to
 * the server
 * @returns A vector of pairs of vectors and strings.
 */
void CommandUploadUnClasified::execute() {
    vector<pair<vector<double>,string>> *classifiedData = new vector<pair<vector<double>,string>>();
    vector<vector<double>> *unClassifiedData = new vector<vector<double>>();

    this->defaultIO->write(Globals::UPLOAD_AN_CLASSIFIED_DATA_TRAIN);
    defaultIO->sendData();
    string line;
    line = defaultIO->read();
    if(line.compare(Globals::INVALID_PATH_BACK_N)==0){
        return;
    }
    /* A function that compares two strings. */
    while(line.compare(Globals::END_OF_FILE_BACK_N) != 0){
        pair<vector<double>,string> p= StringUtils::splitVectorAndVectoryTypeSeinceNumbers(line, ',');
        classifiedData->push_back(p);
        defaultIO->write(Globals::STATUS_CODE_SUCCESS);
        defaultIO->sendData();
        line = defaultIO->read();

    }
    this->defaultIO->write(Globals::UPLOAD_COMPLETE);
    this->defaultIO->sendData();

    this->defaultIO->read();
    this->defaultIO->write(Globals::UPLOAD_AN_CLASSIFIED_DATA_TEST);
    this->defaultIO->sendData();

    line = defaultIO->read();

    if(line.compare(Globals::INVALID_PATH_BACK_N)==0){
        return;
    }
    /* A function that compares two strings. */
    while(line.compare(Globals::END_OF_FILE_BACK_N) != 0){
        pair<vector<double>,string> p= StringUtils::splitVectorAndVectoryTypeSeinceNumbers(line, ',');
        // will this work?
        unClassifiedData->push_back(p.first);
        defaultIO->write(Globals::STATUS_CODE_SUCCESS);
        defaultIO->sendData();
        line = defaultIO->read();
    }



    settings->setClassifiedData(classifiedData);
    settings->setUnClassifiedData(unClassifiedData);
    this->defaultIO->write(Globals::UPLOAD_COMPLETE);
    this->defaultIO->sendData();
    this->defaultIO->read();
}
