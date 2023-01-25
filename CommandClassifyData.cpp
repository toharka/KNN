

#include "CommandClassifyData.h"
#include "StringUtils.h"

/**
 * This function is used to classify the data that has been uploaded
 * @returns The command is returning a pointer to a new instance of the CommandClassifyData class.
 */
void CommandClassifyData::execute() {

    if (settings->getClassifiedData()->empty()) {
        defaultIO->write(Globals::PLEASE_UPLOAD_DATA);
        return;
    }

    if (settings->getUnClassified()->empty()) {
        defaultIO->write(Globals::PLEASE_UPLOAD_DATA);
        return;
    }
    vector<string> newClassified;
    vector<std::pair<std::vector<double>, std::string>> *train = settings->getClassifiedData();
    vector<vector<double>> *test = settings->getUnClassified();
    vector<tuple<vector<double>, string, double>> tup;
    for (int i = 0; i < train->size(); i++) {
        tuple<vector<double>, string, double> t(train->at(i).first, train->at(i).second, 0);
        tup.push_back(t);
    }

    for (int i = 0; i < test->size(); i++) {
        Knn knnObject(settings->getDistanceType(), tup, test->at(i), settings->getK());
        newClassified.push_back(knnObject.vectorType());
    }
    settings->SetClassifiedTest(newClassified);
    defaultIO->write("classifying data complete");


}
