
#ifndef ADVANCEDPROGRAGMMINGMILESTONES_DISTANCECALCULATOR_H
#define ADVANCEDPROGRAGMMINGMILESTONES_DISTANCECALCULATOR_H

#include <vector>

using namespace std;

namespace DistanceCalculator {

    


    /**
     * This function recieve string distance type and returns a calculate distance acordingly.
     * @param distance
     * @return
     */

    double getDistance(const string &distance, vector<double> &v1, vector<double> &v2);

    double calculateDistance(vector<double> &v1, vector<double> &v2, double (*getDistance)(double, double));

    double calculateChebyshev(vector<double> &v1, vector<double> &v2);

    double calculateManhattan(vector<double> &v1, vector<double> &v2);

    double calculateEuclidean(vector<double> &v1, vector<double> &v2);

    double calculateCanberra(vector<double> &v1, vector<double> &v2);

    double calculateMinkowski(vector<double> &v1, vector<double> &v2);
};


#endif //ADVANCEDPROGRAGMMINGMILESTONES_DISTANCECALCULATOR_H
