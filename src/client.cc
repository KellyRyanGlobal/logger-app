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
static easylogger::Logger SUB("SUB");

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
                LOG_ERROR(SUB, " Invalid address\n");
            }
            create_connection();
            
            myfile.open(".//input//results.txt", ios::in | ios::binary);
            if(myfile.is_open()){
                LOG_TRACE(SUB, "File is ready to Transmit.\n");
            }
            else{
                LOG_ERROR(SUB, "File loading failed, Exititng.\n");
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
            LOG_INFO(CLIENT,"sending :" << mystring << "\n");
            LOG_INFO(CLIENT, "bytes sent " << bytes_sent << "\n");
            valread = read( sock , buffer , 1024);
            LOG_INFO(CLIENT, buffer);
            system("./test_app.exe > results.txt");

            // Open the file
            
            string line; //input variable
            myfile.open ("results.txt");
                if (!myfile) // error out if the file could not be opened
                {
                    LOG_ERROR(SUB, "Error: file could not be opened" << line << "\n");
                    exit(1);
                }
            while ( getline (myfile,line) ) 
            {
                
                LOG_INFO(CLIENT, line << "\n");
            // std::cout << mychar;  
            }
            myfile.close();
            LOG_INFO(CLIENT, "end of file" << "\n");
        }
};

int main(){
    Client_socket C;
    SUB.Level(easylogger::LEVEL_WARNING);
	CLIENT.Level(easylogger::LEVEL_TRACE);
    C.send_file();
    return 0;
}
