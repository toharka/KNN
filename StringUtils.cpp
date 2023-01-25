#include <iostream>
#include <string>
#include <vector>
#include "StringUtils.h"
#include<sstream>
#include <cmath>
#include <iomanip>
#include <limits>
#include <map>

using namespace std;

/**
 * splitStringDouble.
 * receives a string and a splitter, and returns a vector.
 * @param str
 * @param splitter
 * @return
 */

tuple<vector<double>, string, int> StringUtils::getVectorArgsFromStringScienceNumbers(string str, char splitter) {
    pair<vector<double>, string> splitResult = splitVectorAndVectoryTypeSeinceNumbers(str, splitter);
    tuple<vector<double>, string, int> result;
    istringstream ss(splitResult.second);
    string distanceType = "";
    get<0>(result) = vector<double>();
    get<1>(result) = "";
    get<2>(result) = -1;
    int counter = 0;
    int k = 0;
    string currentString ="";
    if(splitResult.first.size()==0){
        cout << "invalid input " << endl;
        return result;
    }
    while (!ss.eof() && counter < 2) {
        getline(ss, currentString, splitter);

        if(counter == 0){
            distanceType = currentString;
            if (distanceType != "AUC" && distanceType != "MAN" && distanceType != "CHB" && distanceType != "CAN" && distanceType != "MIN") {
                cout << "invalid input" << endl;
                return result;
            }

        }else if(counter == 1){
            try {
                string kStr = currentString;
                k = stoi(kStr);
            } catch (const std::invalid_argument &) {
                cout << "invalid argument: k is not integer" << endl;
                return result;
            } catch (const std::out_of_range &) {
                cout << "invalid argument k is out of range" << endl;
                return result;
            }

        }
        counter++;
    }
    tuple<vector<double>,string,int> tup(splitResult.first,distanceType,k);
    return tup;
}
tuple<vector<double>, string, int> StringUtils::vectorArgsFromString(string str, char splitter){
    istringstream ss(str);
    string currentString = "";
    vector<double> v;
    string distanceType = "";
    int k = 0;
    int counter = 0;
    tuple<vector<double>, string, int> result;
    get<0>(result) = vector<double>();
    get<1>(result) = "";
    get<2>(result) = -1;
    while (!ss.eof() && counter < 3) {
        getline(ss, currentString, splitter);

        if(counter == 0){
            v = splitStringDouble(currentString,splitter);
            if(v.size()==0){
                cout << "invalid input " << endl;
                return result;
            }
        }else if(counter == 1){
            distanceType = currentString;
            if (distanceType != "AUC" && distanceType != "MAN" && distanceType != "CHB" && distanceType != "CAN" && distanceType != "MIN") {
                cout << "invalid input" << endl;
                return result;
            }

        }else if(counter == 2){
            try {
                string kStr = currentString;
                k = stoi(kStr);
            } catch (const std::invalid_argument &) {
                cout << "invalid argument: k is not integer" << endl;
                return result;
            } catch (const std::out_of_range &) {
                cout << "invalid argument k is out of range" << endl;
                return result;
            }

        }
        counter++;
    }
    tuple<vector<double>,string,int> tup(v,distanceType,k);
    return tup;
}

bool StringUtils::isNumber(string stringNumber){
    try {
        stoi(stringNumber);
        return true;
    } catch (const std::invalid_argument &) {
       

    } catch (const std::out_of_range &) {
        
    }
    return false;
}




vector<double> StringUtils::splitStringDouble(string str, char splitter) {
    istringstream ss(str);
    string number = "";
    vector<double> v;
    while (!ss.eof()) {
        getline(ss, number, splitter);

        if (!validateFloat(number)) {
            vector<double> v2;
            return v2;
        }
        v.push_back(std::stold(number));
    }
    return v;
}

bool
StringUtils::getMainFunctionsValuesForKnn(string input, int &k, string &path, string &distance_type, char splitter) {
    istringstream ss(input);
    string number = "";
    string kStr;

    if (ss.eof()) {
        cout << "There is an invalid input" << endl;
        return false;
    }
    getline(ss, kStr, splitter);
    if (ss.eof()) {
        cout << "There is an invalid input" << endl;

        return false;
    }
    getline(ss, path, splitter);
    if (ss.eof()) {
        cout << "There is an invalid input" << endl;
        return false;
    }
    getline(ss, distance_type, splitter);
    try {
        k = stoi(kStr);
    } catch (exception e) {
        cout << "The 'K' arguemnt is not of integer format, please enter a valid input" << endl;
        return false;
    }
    return true;
}

/**
 * splitStringDouble.
 * receives a string and a splitter, and returns a vector.
 * @param str
 * @param splitter
 * @return
 */
pair<vector<double>, string> StringUtils::splitVectorAndVectoryTypeSeinceNumbers(string str, char splitter) {
    istringstream ss(str);
    string number = "";
    vector<double> v;
    string type;

    bool foundVector = false;
    while (!ss.eof()) {
        getline(ss, number, splitter);
        if (foundVector) {
            string temp = " ";
            temp.append(number);
            type.append(temp);
            continue;
        }
        if (validateFloat(number)) {
            try {
                double n = std::stod(number);
                v.push_back(n);
            } catch (const std::invalid_argument &) {
                foundVector = true;
                type.append(number);
            } catch (const std::out_of_range &) {
                cout << "number is out of range" << endl;
                exit(0);
            }
        } else {

            foundVector = true;

            type.append(number);
        }


    }
    pair<vector<double>, string> p(v, type);
    return p;
}

/**
 * splitStringDouble.
 * receives a string and a splitter, and returns a vector.
 * @param str
 * @param splitter
 * @return
 */
pair<vector<double>, string> StringUtils::splitVectorAndVectoryType(string str, char splitter) {
    istringstream ss(str);
    string number = "";
    vector<double> v;
    string type;
    bool foundVector = false;
    while (!ss.eof()) {
        getline(ss, number, splitter);
        if (foundVector) {
            type.append(number);
            continue;
        }
        if (!validateFloat(number)) {
            foundVector = true;
            type.append(number);
            continue;
        }
        v.push_back(std::stof(number));
    }
    pair<vector<double>, string> p(v, type);
    return p;
}

/**
 * vadliateFloat.
 * recives a number in string and checks if it is really a number.
 * @param number
 * @return
 */
bool StringUtils::validateFloat(string number) {
    if (number.empty()) {
        return false;
    }
    if (number.at(0) == 'E' || number.at(number.size() - 1) == 'E' ||
        number.size() > 1 && number.at(number.size() - 2) == 'E') {
        return false;
    }
    bool foundE = false;
    bool found_point = false;
    for (int i = 0; i < number.size(); i++) {
        if (number[i] == '.') {
            if (found_point) {
                return false;
            }
            found_point = true;
        } else if (number[i] == 'E') {
            if (foundE) {
                return false;
            }
            if (number[i + 1] == '+' || number[i + 1] == '-') {
                foundE = true;
                i++;
                continue;
            } else {
                return false;
            }
        } else {
            int digit = number[i] - '0';
            if (digit < 0 || digit > 9) {
                return false;
            }
        }
    }
    if (number[number.size() - 1] == '.') {
        return false;
    }
    return true;
}

/**
 * printNumber, it will print a number.
 * If the number is integer it will print number.0.
 * If the number is float, it will print with precise of 10 trailing digits after the dot.
 * @param os
 * @param number
 */
void StringUtils::printNumber(ostream &os, double number) {
    if (number - floor(number) == 0) {
        os << fixed << setprecision(1) << number << '\n';
    } else {
        os << fixed << setprecision(10) << number << '\n';
    }
}

void StringUtils::printVector(ostream &os, vector<double> v) {
    /* A for loop that iterates over the vector. */
    for (int i = 0; i < v.size(); i++) {
        os << v.at(i) << ",";
    }
    os << endl;
}

void StringUtils::printAllVectors(ostream &os, vector<vector<double>> v) {
    for (int i = 0; i < v.size(); i++) {
        printVector(os, v.at(i));
    }
    os << endl;
}

void StringUtils::printPair(ostream &os, pair<vector<double>, string> p) {
    for (int i = 0; i < p.first.size(); i++) {
        os << p.first.at(i) << ",";
    }

    os << p.second << endl;
}

void StringUtils::printMap(ostream &os, map<vector<double>, string> m) {
    for (pair<vector<double>, string> p: m) {
        printPair(os, p);
    }
}


