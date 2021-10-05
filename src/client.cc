// Client side C/C++ program to demonstrate Socket programming
#include "easylogger.h"
#include <stdio.h>
#include <sys/socket.h>
#include <fstream>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>


#define PORT 8081

using namespace std;

static easylogger::Logger HOST("HOST");


int main(int argc, char const *argv[])
{
    int sock = 0, valread;
    struct sockaddr_in serv_addr;
    char hello[] = "Hello from client";
    std::string mystring;
    char buffer[1024] = {0};
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        cout << "\n Socket creation error \n";
        return -1;
    }
   
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
       
    // Convert IPv4 and IPv6 addresses from text to binary form
    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0) 
    {
        cout << "\nInvalid address/ Address not supported \n";
        return -1;
    }
   
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        cout << "\nConnection Failed \n";
        return -1;
    }
    send(sock , hello , strlen(hello) , 0 );
    cout << "Hello message sent\n";
    valread = read( sock , buffer , 1024);
    cout << buffer << endl;;
    system("./test_app.exe > results.txt");

    // Open the file
    ifstream myfile;
    string line; //input variable
    myfile.open ("results.txt");
        if (!myfile) // error out if the file could not be opened
        {
            cerr << "Error: file could not be opened" << line << endl;
            exit(1);
        }
    while ( getline (myfile,line) ) 
    {
        
        cout << line << endl;
       // std::cout << mychar;  
    }
    myfile.close();
    cout << "end of file" << endl;
    return 0;
}
