
#include "Settings.h"



void Settings:: set(string distype, int k){
this->distance_type= distype;
this->k=k;
}

string Settings:: getDistanceType(){

return this->distance_type;

}
int Settings::getK(){
return k;

}
void Settings::pushClassifiedData(pair<vector<double>, string> p) {
    this->classifiedData->push_back(p);
}
vector<pair<vector<double>, string>>* Settings::getClassifiedData() {
    return this->classifiedData;
}

void Settings:: SetClassifiedTest(vector<string> classifiedTest){
    this->classifiedTest=classifiedTest;


}
vector<vector<double>>* Settings:: getUnClassified(){
return this->unClassifiedData;

}
vector<string> Settings:: getClassifiedTest(){

return this->classifiedTest;



}
void Settings::pushUnclassifiedData(vector<double> v) {
    this->unClassifiedData->push_back(v);
    
}

void Settings::setClassifiedData(vector<pair<vector<double>,string>> *classifiedData) {
    if(this->classifiedData != nullptr) {
        delete this->classifiedData;
    }
    this->classifiedData = classifiedData;
}
void Settings::setUnClassifiedData(vector<vector<double>> *unClassifiedData) {
    if(this->unClassifiedData != nullptr) {
        delete this->unClassifiedData;
    }
    this->unClassifiedData = unClassifiedData;
}

vector<vector<double>> *Settings::getUnClassifiedData() {
    return this->unClassifiedData;
}





