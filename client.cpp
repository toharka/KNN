
#include <iostream>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include "StringUtils.h"
#include <vector>
using namespace std;
/* This is the main function of the client. It takes the ip address and the port number as arguments.
Then it creates a socket and connects to the server. */
int clientMain(int argc, char **argv) {
if (argc < 3) {
        cout << "some of the arguments are missing" << endl;
        return 0;
    }
//const char* ip_address = argv[1];
const char* ip_address = argv[1];

string portStr = argv[2];
const int port_no = stoi(portStr);
int sock = socket(AF_INET, SOCK_STREAM, 0);
if (sock < 0) {
perror("error creating socket");
return 0;
}
/* This is the code that connects the client to the server. */
struct sockaddr_in sin;
memset(&sin, 0, sizeof(sin));
sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = inet_addr(ip_address);
    sin.sin_port = htons(port_no);
if (connect(sock, (struct sockaddr *) &sin, sizeof(sin)) < 0) {
perror("error connecting to server");
return 0;
}
while (1)
{
/* This is the code that gets the input from the user and checks if it is valid. */
string vectorStr = "";
getline(cin,vectorStr);
if(vectorStr=="-1"){
    break;
}
tuple<vector<double>, string, int> myTup=StringUtils::getVectorArgsFromStringScienceNumbers(vectorStr, ' ');
if (get<2>(myTup) ==-1)
{
    continue;
}
/* This is the code that sends the data to the server. */
const char* data = vectorStr.c_str();
char data_addr[4096];
strcpy(data_addr,data);
int data_len = strlen(data_addr);
int sent_bytes = send(sock, data_addr, data_len, 0);
if (sent_bytes < 0) {
cout << "there is an error " << endl;
return 0;
}

/* This is the code that receives the data from the server. */
char buffer[4096]="";
int expected_data_len = sizeof(buffer);
int read_bytes = recv(sock, buffer, expected_data_len, 0);
if (read_bytes == 0) {
break;
}
else if (read_bytes < 0) {
break;
}
else {
cout << buffer<<endl;
}
}
close(sock);
return 0;
}