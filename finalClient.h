//
// Created by lioze on 1/22/2023.
//

#ifndef FINALSTONE_FINALCLIENT_H
#define FINALSTONE_FINALCLIENT_H
#include <string>
#include <vector>
using namespace std;

class finalClient {
public:
    static void run(const char* ip,const int port);
    static void saveFile(string filepath,vector<string> &classified);
};


#endif //FINALSTONE_FINALCLIENT_H
