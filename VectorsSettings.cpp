//
// Created by lioze on 1/21/2023.
//

#include "VectorsSettings.h"
void VectorsSettings::pushClassifiedData(pair<vector<double>, string> p) {
    this->classifiedData.push_back(p);
}

vector<pair<vector<double>, string>> VectorsSettings::getClassifiedData() {
    return vector<pair<vector<double>, string>>();
}

void VectorsSettings::pushUnclassifiedData(vector<double> v) {
    this->unClassifiedData.push_back(v);
}
