//
// Created by lioze on 1/15/2023.
//

#include "StandardIO.h"
#include <string>

#include <iostream>

using namespace std;

void StandardIO::write(string data) {
    responseQueue.push(data);
}


string StandardIO::read(){
    string str = "";
    getline(cin,str);
    return str;
}

void StandardIO::sendData() {
    while(!responseQueue.empty()){
        cout <<  responseQueue.front() << endl;
        responseQueue.pop();
    }
}

void StandardIO::waitForSuccess() {

}

void StandardIO::closeSocket() {

}
