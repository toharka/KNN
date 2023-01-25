
#ifndef ADVANCEDPROGRAGMMINGEX2_Knn_H
#define ADVANCEDPROGRAGMMINGEX2_Knn_H

#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include "DistanceCalculator.h"

using namespace std;
using namespace DistanceCalculator;

class Knn {
private:
string distance_type;
vector<tuple<vector<double>, string, double>> tupVector;
int k;
vector<double> vec;

   
public:

Knn(string distype, vector<tuple<vector<double>, string, double>> tup, vector<double> vec, int k);
void distance_vec();
string vectorType() ;
string  max(map<string,int> newMap);

private:
    void initiateDistance();

};
    

#endif //ADVANCEDPROGRAGMMINGEX2_Knn_H