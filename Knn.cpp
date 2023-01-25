#include "Knn.h"
#include <iostream>
#include "StringUtils.h"
#include<bits/stdc++.h>

/// @brief  conctructor of Knn class
/// @param type 
/// @param map 
/// @param vec_values 
/// @param k 

Knn::Knn(string disType, vector<tuple<vector<double>, string, double>> tup, vector<double> vec_values, int k) {
    this->distance_type = disType;
    this->tupVector = tup;
    this->vec = vec_values;
    this->k = k;
    distance_vec();
}


/// @brief  the function distance_vec takes map of vector as key and string as value and for ech vector calculate.
/// the  distance to the given vector and create vector of pairs that have the string name and itt distance to the given vector. 
/// @return vector of pairs <string,distance>
void Knn::distance_vec() {
    {
        vector<pair<string, double>> distanceVector;
        for (int i = 0; i < tupVector.size(); i++) {
            std::get<2>(tupVector.at(i)) = getDistance(distance_type, vec, std::get<0>(tupVector.at(i)));
        }

    }

    // sort from the library  and conpere by second element of the pair.
    std::sort(tupVector.begin(), tupVector.end(), [](const tuple<vector<double>, string, double> &left,
                                                     const tuple<vector<double>, string, double> &right) {
        return get<2>(left) < get<2>(right);
    });


}


/// @brief the function vectorType get from distace_vec sorted vector of pairs that have string vector name
/// and it distance from given vector for the k lowest element the for loop create a map and gor ech name of vector the 
/// map calculate how much time this name is is shown in the k first element of the vector,
/// for ech time the name shown the value of the key name increment by 1 
/// finally the function witch value of the map is the graetest with the function max and return the key.
/// @return 
string Knn::vectorType() {
    map<string, int> newMap;
    for (int i = 0; i < this->k and i < this->tupVector.size(); i++) {
        string key = get<1>(tupVector.at(i));
        if (newMap.count(key) == 0) {
            newMap[key] = 1;
        } else {
            newMap[key]++;
        }
    }
    return Knn::max(newMap);

}

/// @brief the function map find witch value of the map is the max value and return the key.
/// @param newMap 
/// @return 
string Knn::max(map<string, int> newMap) {
    map<string, int> myMap = newMap;
    int max_value = 0;
    string max_key = "";
    for (pair<string, int> p: myMap) {
        if (p.second > max_value) {
            max_value = p.second;
            max_key = p.first;
        }
    }
    return max_key;
}



















