//
// Created by lioze on 12/4/2022.
//
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#ifndef ADVANCEDPROGREMMINGEX2_DATAADAPTER_H
#define ADVANCEDPROGREMMINGEX2_DATAADAPTER_H
using namespace std;

class DataAdapter {
public:
    vector<tuple<vector<double>, string, double>> getClassifiedData();

    DataAdapter(string path);

private:

    std::string path;
    vector<tuple<vector<double>,string,double>> classifiedData;

    void loadData(ifstream &stream, string &distanceType, vector<double> v1);

    void loadData(ifstream &stream);
};




#endif //ADVANCEDPROGREMMINGEX2_DATAADAPTER_H
