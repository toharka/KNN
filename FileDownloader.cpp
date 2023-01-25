//
// Created by lioze on 1/24/2023.
//
#include <fstream>
#include <iostream>
#include "FileDownloader.h"
/**
 * It opens a file and writes the data to it
 */
void FileDownloader::download() {
    int length = this->data.size();
    ofstream file(this->path);
    if (file.is_open()) {

        for (int i = 0; i < length; i++) {

            int k = i + 1;
            file << this->data.at(i);

        }
        file.close();
    } else {
        std::cout << "Failed to open file" << std::endl;
    }

}
