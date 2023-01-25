//
// Created by lioze on 1/24/2023.
//

#ifndef FINALSTONE_FILEDOWNLOADER_H
#define FINALSTONE_FILEDOWNLOADER_H

#include <string>
#include <utility>
#include <vector>
using namespace std;
class FileDownloader {
private:
    string path;
    vector<string> data;
public:
    FileDownloader(string path, vector<string> data): path(std::move(path)), data(data){

    }

    void download();




};


#endif //FINALSTONE_FILEDOWNLOADER_H
