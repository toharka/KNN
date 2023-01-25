//
// Created by lioze on 1/21/2023.
//

#ifndef SERVERMILESTONEEX3_VECTORSSETTINGS_H
#define SERVERMILESTONEEX3_VECTORSSETTINGS_H

#include <vector>
#include <string>

using namespace std;
class VectorsSettings {
private:
    vector<pair<vector<double>,string>> classifiedData;
    vector<vector<double>> unClassifiedData;
public:
    vector<pair<vector<double>,string>> getClassifiedData();
    void pushClassifiedData(pair<vector<double>,string> p);
    void pushUnclassifiedData(vector<double> v);

};


#endif //SERVERMILESTONEEX3_VECTORSSETTINGS_H
