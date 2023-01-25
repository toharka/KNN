////
//// Created by lioze on 1/2/2023.
////
//
//#include "server.h"
//#include "DataAdapter.h"
//#include "Knn.h"
//#include "StringUtils.h"
//#include <netinet/in.h>
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <sys/socket.h>
//#include <unistd.h>
//#include <iostream>
//#include <cstring>
//#include <utility>
//
//
//using namespace std;
//DataAdapter getDataAdapterInstance(string path);
//void runServer(int server_port,DataAdapter adapter);
//string getVectorType(DataAdapter adapter, vector<double> v,string distanceType, int k);
//
//int run(int argc, char **argv);
//
///**
// * It creates a server that listens to the given port and when a client connects to it, it sends the
// * data to the client
// *
// * @param argc the number of arguments passed to the program
// * @param argv argv[1 ]
// *
// * @return
// */
//int Server::run(int argc, char **argv){
//
//    if (argc < 3) {
//        cout << "some of the arguments are missing" << endl;
//        exit(0);
//    }
//    int server_port = 0;
//    string distanceType = "";
//    string path = argv[1];
//    try {
//        string portStr = argv[2];
//        server_port = stoi(portStr);
//    } catch (const std::invalid_argument &) { // remember to add if for maximum port number 2^something
//        cout << "invalid argument: port is not integer" << endl;
//        exit(0);
//    } catch (const std::out_of_range &) {
//        cout << "invalid argument port is out of range" << endl;
//        exit(0);
//    }
//    DataAdapter adapter = getDataAdapterInstance(path);
//    runServer(server_port,adapter);
//    return 0;
//}
//
///**
// * It returns a DataAdapter object.
// *
// * @param path the path to the file
// *
// * @return A DataAdapter object
// */
//DataAdapter getDataAdapterInstance(string path){
//    DataAdapter adapter(std::move(path));
//    if(adapter.getClassifiedData().empty()){
//        cout << "file is empty" <<endl;
//        exit(0);
//    }
//    return adapter;
//}
//void runServer(int server_port,DataAdapter adapter){
//
//   /* It creates a socket and binds it to the port. */
//    int sock = socket(AF_INET, SOCK_STREAM, 0);
//    if (sock < 0) {
//        perror("error creating socket");
//    }
//    struct sockaddr_in sin;
//    memset(&sin, 0, sizeof(sin));
//    sin.sin_family = AF_INET;
//    sin.sin_addr.s_addr = INADDR_ANY;
//    sin.sin_port = htons(server_port);
//    if (bind(sock, (struct sockaddr *) &sin, sizeof(sin)) < 0) {
//        perror("error binding socket");
//    }
//     if (listen(sock, 1) < 0) {
//            perror("error listening to a socket");
//        }
//
//    bool running = true;
//   /* Waiting for a client to connect to the server. */
//    while (running)
//    {
//        struct sockaddr_in client_sin;
//        unsigned int addr_len = sizeof(client_sin);
//        int client_sock = accept(sock, (struct sockaddr *) &client_sin, &addr_len);
//        if (client_sock < 0) {
//            perror("error accepting client");
//        }
//        while (running) {
//          /* Reading the client's message. */
//            char clientMessageArguments[4096] = "";
//            int expected_data_len = sizeof(clientMessageArguments);
//            int read_bytes = recv(client_sock, clientMessageArguments, expected_data_len, 0);
//            if (read_bytes == 0) {
//
//                break;
//            }else if (read_bytes < 0) {
//                // error
//
//            } else {
//                if (strcmp(clientMessageArguments, "-1") == 0) {
//                    break;
//                }
//               /* it is parsing the message to get the vector, the
//               distance type and the k value.
//               Then it is calling the getVectorType function to get the type of the vector.
//               Then it is sending the type of the vector to the client. */
//                tuple<vector<double>, string, int> tup = StringUtils::getVectorArgsFromStringScienceNumbers(clientMessageArguments, ' ');
//                string vectorType = getVectorType(adapter, get<0>(tup), get<1>(tup), get<2>(tup));
//                char message[4096] = "";
//                strcpy(message, vectorType.c_str());
//                int sent_bytes = send(client_sock, message, 4096, 0);
//                if (sent_bytes < 0) {
//                    perror("error sending to client");
//                }
//        }
//    }
//}
//close(sock);
//}
///**
// * It takes in a data adapter, a vector, a distance type, and a k value, and returns the type of the
// * vector
// *
// * @param adapter the DataAdapter object that contains the classified data
// * @param v the vector you want to classify
// * @param distanceType the type of distance to be used.
// * @param k the number of nearest neighbors to consider
// *
// * @return the type of the vector.
// */
//string getVectorType(DataAdapter adapter, vector<double> v,string distanceType, int k){
//    if(v.empty() || get<0>(adapter.getClassifiedData().at(0)).size() != v.size()){
//    string message ="invalid input";
//    return message;
//
//    }else{
//        Knn knnObject(distanceType,adapter.getClassifiedData(),v, k);
//        return knnObject.vectorType();
//    }
//}
