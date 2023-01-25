
#include <map>
#include "DataAdapter.h"
#include "StringUtils.h"
#include "DistanceCalculator.h"

DataAdapter::DataAdapter(string path) {
    this->path = path;
    ifstream file(path);
    loadData(file);
    file.close();
}

/**
 *
 * @param stream
 * @param distanceType
 */
void DataAdapter::loadData(ifstream &stream) {
    int test = 0;
    try {
        string line;
        vector<tuple<vector<double>, string, double>> vectors;
        while (getline(stream, line)) {
            StringUtils::splitVectorAndVectoryType(line, ',');
            pair<vector<double>, string> p = StringUtils::splitVectorAndVectoryTypeSeinceNumbers(line, ',');

//            if(v1.size() != p.first.size()){
//                cout << "line is: " << line << endl;
//                cout << "error vectors are not of the same size"  << v1.size()<< " , "  << p.first.size()<<  " " << test << endl;
//                StringUtils::printVector(cout,p.first);
//                return;
//            }
            tuple<vector<double>, string, double> t(p.first, p.second, 0);
            vectors.push_back(t);
            line = "";
        }
        this->classifiedData = vectors;
    }
    catch (const ifstream::failure &e) {
        cout << "Exception opening/reading file" << endl;
        return;
    }

}

vector<tuple<vector<double>, string, double>> DataAdapter::getClassifiedData() {
    return this->classifiedData;
}


