#include "finalClient.h"
#include <iostream>
#include <sys/socket.h>

#include <netinet/in.h>
#include <arpa/inet.h>

#include <unistd.h>
#include <stdlib.h>
#include "FileDownloader.h"
#include <string>
#include "StringUtils.h"
#include "SocketIO.h"
#include "StandardIO.h"
#include <vector>
#include <cstring>
#include <fstream>
#include "Globals.h"
#include "IrisFileUtils.h"
#include <thread>
using namespace std;



/**
 * It takes in the IP address and port number as command line arguments, and then calls the run
 * function of the finalClient class
 * @param {int} argc - the number of arguments passed to the program
 * @param {char} argv - 
 * @returns The return value is the number of bytes that were sent.
 */
int main (int argc, char **argv){
if (argc < 3) {
        cout << "some of the arguments are missing" << endl;
        return 0;
        cout<<"dfs";
    }

const char* ip_address = argv[1];

string portStr = argv[2];
const int port_no = stoi(portStr);
finalClient::run(ip_address,port_no);



}

/* This is the main function of the client. It takes the ip address and the port number as arguments.
Then it creates a socket and connects to the server. */
/**
 * It connects to the server, reads the data from the server, and writes the data to the server
 * @param {char} ip - the ip address of the server
 * @param {int} port - The port number that the server is listening on.
 * @returns a pointer to a new instance of the class.
 */
void finalClient::run(const char* ip,const int port) {


    const char *ip_address = ip;
    
    const int port_no = port;
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("error creating socket");
        return;
    }
/* This is the code that connects the client to the server. */
    struct sockaddr_in sin;
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = inet_addr(ip_address);
    sin.sin_port = htons(port);
    if (connect(sock, (struct sockaddr *) &sin, sizeof(sin)) < 0) {
        perror("error connecting to server");
        return;
    }
    SocketIO *socketIO = new SocketIO(sock);
    StandardIO standardIo;
    bool running = true;

    while (running) {

//        char data[4092] = "200";
//        send(sock,data,4092,0);
        string data = socketIO->read();
        if(data.compare(Globals::EXIT_DESCRIPTION_BACK_N)==0){
            break;
        }
        if(data.compare(Globals::DISPLAY_RESULT_SYNCRONIZED_BACK_N)==0){
            socketIO->write(Globals::STATUS_CODE_SUCCESS);
            socketIO->sendData();

            while(data.compare(Globals::DISPLAY_RESULT_END_BACK_N)!=0){
                data = socketIO->read();
                cout << data;
                socketIO->write(Globals::STATUS_CODE_SUCCESS);
                socketIO->sendData();
            }
            continue;
        }

        if(data.compare(Globals::DISPLAY_RESULT_UN_SYNCRONIZED_BACK_N)==0){
            cout << "please enter path" << endl;
            string path = standardIo.read();
            socketIO->write(Globals::STATUS_CODE_SUCCESS);
            socketIO->sendData();
            vector<string> downloadResults;
            data = socketIO->read();

            while(data.compare(Globals::DISPLAY_RESULT_END_BACK_N)!=0){
                downloadResults.push_back(data);
                socketIO->write(Globals::STATUS_CODE_SUCCESS);
                socketIO->sendData();
                data = socketIO->read();
            }
            socketIO->write(Globals::STATUS_CODE_SUCCESS);
            socketIO->sendData();
            FileDownloader *downloader = new FileDownloader(path,downloadResults);
            thread downloader2(&FileDownloader::download,downloader);
            downloader2.detach();
            continue;
        }


        cout << data;

        if (data.compare(Globals::UPLOAD_AN_CLASSIFIED_DATA_TEST_BACK_N) == 0 ||
            data.compare(Globals::UPLOAD_AN_CLASSIFIED_DATA_TRAIN_BACK_N) == 0) {
            string path = standardIo.read();
            IrisFileUtils::readFile(path, socketIO);

        } else if (data.compare(Globals::UPLOAD_COMPLETE_BACK_N) == 0) {
            socketIO->write(Globals::STATUS_CODE_SUCCESS);
            socketIO->sendData();
        } else {
            string message = standardIo.read();
            socketIO->write(message);
            socketIO->sendData();
        }
    }
    close(sock);
}

 void finalClient::saveFile(string filepath,vector<string> &classified) {
    int length = classified.size();
    ofstream file(filepath);
    if (file.is_open()) {

        for (int i = 0; i < length; i++) {
            int k = i + 1;
            file << classified.at(i);

        }
        file.close();
    } else {
        std::cout << "Failed to open file" << std::endl;
    }
}





