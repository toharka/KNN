
#include "IrisFileUtils.h"
#include "DefaultIO.h"
#include <string>
#include <iostream>
#include <fstream>
#include "Globals.h"
using namespace std;


/**
 * It reads a file line by line and sends it to the client
 * @param {string} path - The path to the file to be read.
 * @param {DefaultIO} defaultIo - This is the object that is used to send and receive data from the
 * client.
 * @returns a string.
 */
void IrisFileUtils::readFile(string path, DefaultIO *defaultIo) {
    ifstream file(path);

    string line;
    if(!file.is_open()){
        cout << "Invalid path" << endl;
        defaultIo->write(Globals::INVALID_PATH);
        defaultIo->sendData();
        file.close();
        return;
    }
    try {
        while (getline(file, line)) {
            defaultIo->write(line);
            defaultIo->sendData();
            string response = defaultIo->read();

        }
    }
    catch (const ifstream::failure &e) {
        cout << "Invalid path" << endl;
        defaultIo->write(Globals::INVALID_PATH);
        defaultIo->sendData();
        file.close();
        return;
    }
    defaultIo->write(Globals::END_OF_FILE);
    defaultIo->sendData();
    file.close();
}