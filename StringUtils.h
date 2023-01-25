
#ifndef STRINGUTILS_H
#define STRINGUTILS_H

#include <vector>
#include <string>
#include <map>

using namespace std;
namespace StringUtils {
    bool validateFloat(string number);

    vector<double> splitStringDouble(string str, char splitter);

    void printNumber(ostream &os, double number);

    pair<vector<double>, string> splitVectorAndVectoryType(string str, char splitter);

    void printPair(ostream &os, pair<vector<double>, string> p);

    void printMap(ostream &os, std::map<vector<double>, string> p);

    void printVector(ostream &os, vector<double> v);

    void printAllVectors(ostream &os, vector<vector<double>> v);

    bool getMainFunctionsValuesForKnn(string input, int &k, string &path, string &distance_type, char splitter);

    pair<vector<double>, string> splitVectorAndVectoryTypeSeinceNumbers(string str, char splitter);

    tuple<vector<double>, string, int> vectorArgsFromString(string str, char splitter);

    tuple<vector<double>, string, int> getVectorArgsFromStringScienceNumbers(string str, char splitter);

    bool isNumber(string stringNumber);
}

#endif
