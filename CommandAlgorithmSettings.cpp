
#include "StringUtils.h"
#include "CommandAlgorithmSettings.h"
#include<sstream>

/**
 * The function is used to change the KNN parameters.
 * @returns the current KNN paramters are K = "+to_string(settings->getK())+", distance metric =
 * "+settings->getDistanceType()
 */
void CommandAlgorithmSettings::execute() {
    //im not sure we need here this write function but if we should its here
    int t = settings->getK();
    defaultIO->write("the current KNN paramters are K = "+to_string(settings->getK())+", distance metric = "+settings->getDistanceType());
    defaultIO->sendData();
    string str = defaultIO->read();
    if (str.compare("\n")==0)
    {
        return;
    }
    
    istringstream ss(str);
    getline(ss, str, ' ');
    string distanceType = "";
    int k = 0;
    string kCheck;
    try
    {
          k=stoi(str);

          if (k<=0)
          {
            defaultIO->write("invalid value for K");
            kCheck="invalid value for K";
          }
          
        if (k>settings->getClassifiedData()->size())
        {
             defaultIO->write("invalid value for K");
             kCheck="invalid value for K";
        }
        
    }
    catch(const std::exception& e)
    {
         defaultIO->write("invalid value for K");
         kCheck="invalid value for K";

    }
    str = "";
    getline(ss, str);
    distanceType=str;
    if (distanceType != "AUC" && distanceType != "MAN" && distanceType != "CHB" && distanceType != "CAN" && distanceType != "MIN") {
            defaultIO->write("invalid value for metric");
            return;
      }
    if (kCheck=="invalid value for K")
    {
        return;
    }
    
    settings->set( distanceType, k);
    // maybe we need to write abd send the new k and matric but i think we dont 

}




