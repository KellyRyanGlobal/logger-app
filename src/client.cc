// Client side C/C++ program to demonstrate Socket programming
#include "easylogger.h"
#include <stdio.h>
#include <sys/socket.h>
#include <fstream>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>


#define PORT 8050

using namespace std;

static easylogger::Logger CLIENT("CLIENT");


class Client_socket{

    fstream myfile;
    int sock = 0, valread, address_length;
    struct sockaddr_in serv_addr;
    //char hello[] = "Hello from client";
    char buffer[1024] = {0};

    public:
        Client_socket () {            
            create_socket();   
                
            serv_addr.sin_family = AF_INET;
            serv_addr.sin_addr.s_addr = INADDR_ANY; 
            serv_addr.sin_port = htons(PORT);
            address_length = sizeof(serv_addr);

            if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0) { 
                cout<<" Invalid address\n";
            }
            create_connection();
            
            myfile.open(".//input//results.txt", ios::in | ios::binary);
            if(myfile.is_open()){
                cout << "[LOG] : File is ready to Transmit.\n";
            }
            else{
                cerr << "[ERROR] : File loading failed, Exititng.\n";
                exit(EXIT_FAILURE);
            }
        }
            // Convert IPv4 and IPv6 addresses from text to binary form
        void create_socket() {
            if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
            {
                cout << "\n Socket creation error \n";                
                exit(EXIT_FAILURE);
            }            
        }

        void create_connection () {
            if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
            {
                cout << "\nConnection Failed \n";
                exit(EXIT_FAILURE);
            }
            cout << "connection Successful\n";
        }

        void send_file() 
        {
            std::string mystring ((std::istreambuf_iterator<char>(myfile)), std::istreambuf_iterator<char>());
            int bytes_sent = send(sock , mystring.c_str() , mystring.length() , 0 );
            cout << "sending :" << mystring << endl;
            cout << "bytes sent " << bytes_sent << endl;
            valread = read( sock , buffer , 1024);
            cout << buffer << endl;;
            system("./test_app.exe > results.txt");

            // Open the file
            
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
        }
};

int main(){
    Client_socket C;
    LOG_INFO(CLIENT, "obtained information");
    C.send_file();
    return 0;
}
