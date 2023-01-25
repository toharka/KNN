
#include <iostream>
#include <cmath>
// need to check if v1 != v2
#include <utility>
#include <vector>
#include "DistanceCalculator.h"

using namespace std;


/// @brief DistanceCalculator is a class which contains
/// @brief calculate distance is a function which recived 2 vectors,
///        and return distance between them using the getDistance parm function.
double
DistanceCalculator::calculateDistance(vector<double> &v1, vector<double> &v2, double (*getDistance)(double, double)) {
    double result = 0;
    for (int i = 0; i < v1.size(); i++) {
        result += getDistance(v1.at(i), v2.at(i));
    }
    return result;
}

/// @brief calculateChebyshev
/// @return double the distance of the calculated distance.
double DistanceCalculator::calculateChebyshev(vector<double> &v1, vector<double> &v2) {
    double maxResult = -1;
    for (int i = 0; i < v1.size(); i++) {
        double result = abs(v1.at(i) - v2.at(i));
        if (result > maxResult) {
            maxResult = result;
        }
    }

    return maxResult;
}


/**
 * Calculate the Manhattan distance between two vectors.
 *
 * @return A function that takes two doubles and returns a double.
 */
double DistanceCalculator::calculateManhattan(vector<double> &v1, vector<double> &v2) {
    return DistanceCalculator::calculateDistance(v1, v2, [](double d1, double d2) {
        double result = abs(d1 - d2);
        return result;
    });
}

/// @brief  calculating the Canberra distance.
/// @return double - the Canberra distance.
double DistanceCalculator::calculateCanberra(vector<double> &v1, vector<double> &v2) {

    return DistanceCalculator::calculateDistance(v1, v2, [](double d1, double d2) {
        double numorator = abs(d1 - d2);
        double denominator = abs(d1) + abs(d2);
        return numorator / denominator;
    });
}

/// @brief  calculating the Eulidean distance.
/// @return double - the eludian distance.
double DistanceCalculator::calculateEuclidean(vector<double> &v1, vector<double> &v2) {
    double result = calculateDistance(v1, v2, [](double d1, double d2) {
        double result = pow(d1 - d2, 2);
        return result;
    });
    return sqrt(result);
}

/// @brief  calculating the Minkowski distance.
/// @return double - the Minkowski distance.
double DistanceCalculator::calculateMinkowski(vector<double> &v1, vector<double> &v2) {
    double result = 0;
    for (int i = 0; i < v1.size(); ++i) {
        result += pow(abs(v1.at(i) - v2.at(i)), 2);
    }
    return sqrt(result);

}

/**
   * This function recieve string distance type and returns a calculate distance acordingly.
   * @param distance
   * @return
   */
double DistanceCalculator::getDistance(const std::string &distance, vector<double> &v1, vector<double> &v2) {
    if (distance == "AUC") {
        return calculateEuclidean(v1, v2);
    } else if (distance == "MAN") {
        return calculateManhattan(v1, v2);
    } else if (distance == "CHB") {
        return calculateChebyshev(v1, v2);
    } else if (distance == "CAN") {
        return calculateCanberra(v1, v2);
    }
    return calculateMinkowski(v1, v2);
}
