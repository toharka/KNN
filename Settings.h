
#ifndef ADVANCEDPROGRAGMMINGFINAL_SETTINGS_H
#define ADVANCEDPROGRAGMMINGFINAL_SETTINGS_H


#include <string>
#include <vector>

using namespace std;


class Settings {
private:
vector<vector<double>> *unClassifiedData;
vector<pair<vector<double>,string>> *classifiedData;
vector<string> classifiedTest;
string distance_type;
int k;



public:
Settings(string &distance_type, int k):distance_type(distance_type),k(k){
    this->unClassifiedData = new vector<vector<double>>();
    this->classifiedData = new vector<pair<vector<double>,string>>();
}


void setClassifiedData(vector<pair<vector<double>,string>> *classifiedData);
void setUnClassifiedData(vector<vector<double>>  *unClassifiedData);
    vector<pair<vector<double>, string>>* getClassifiedData();
void set(string distype, int k);
string getDistanceType();
int getK();
void pushClassifiedData(pair<vector<double>,string> p);
void pushUnclassifiedData(vector<double> v);
void SetClassifiedTest(vector<string> classifiedTest);

vector<vector<double>> * getUnClassified();

    vector<string> getClassifiedTest();

    vector<vector<double>> *getUnClassifiedData();
};

#endif //ADVANCEDPROGRAGMMINGFINAL_SETTINGS_H