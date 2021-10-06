
// Server side C/C++ program to demonstrate Socket programming

#include "easylogger.h"
#include "template_functions.h"
#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <fstream>

#define PORT 8050

static easylogger::Logger SERVER("SERVER");
static easylogger::Logger SUB("SUB");

class Server_socket{

    fstream myfile;
    int server_fd, valread, opt = 1, new_socket, address_length;
    struct sockaddr_in address;
    int addrlen;
    char buffer[1024] = {0};
    // char hello[] = "Hello from server";
    
    public:
        Server_socket () {
            create_socket();
                
            address.sin_family = AF_INET;
            address.sin_addr.s_addr = INADDR_ANY;
            address.sin_port = htons( PORT );            
            address_length = sizeof(address);

            bind_socket();
            set_listen_set();
            accept_connection();

            myfile.open(".//output//output.out", ios::out | ios::trunc | ios::binary);
            if(myfile.is_open()) {
                LOG_INFO(SERVER, "File Creted.\n");
            }
            else{
                LOG_ERROR(SUB, " File creation failed, Exititng.\n");
                exit(EXIT_FAILURE);
            }
        }
        // Creating socket file descriptor
        void create_socket() {
            if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
            {
                LOG_ERROR(SUB, "socket failed\n");
                exit(EXIT_FAILURE);
            }
            LOG_INFO(SERVER," Socket Created\n");
        }
        // Forcefully attaching socket to the port 8080
        // if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
        //                                             &opt, sizeof(opt)))
        // {
        //     perror("setsockopt");
        //     exit(EXIT_FAILURE);
        // }
        
        // Forcefully attaching socket to the port 8080
        void bind_socket() {
            if (bind(server_fd, (struct sockaddr *)&address, 
                                        sizeof(address))<0)
            {
                LOG_ERROR(SUB,  "Bind failed\n");
                exit(EXIT_FAILURE);
            }
            cout << " Bind Successful.\n";
        }

        void set_listen_set() {
            if (listen(server_fd, 3) < 0)
            {
                cerr <<  "listen\n";
                exit(EXIT_FAILURE);
            }
            cout << " Socket Listening\n";
        }

        void accept_connection() {
            if ((new_socket = accept(server_fd, (struct sockaddr *)&address, 
                            (socklen_t*)&addrlen))<0)
            {
                cerr << "accept";
                exit(EXIT_FAILURE);
            }
            cout << "Connected to client\n";
        }

        void receive_file(){
            char buffer[1024] = {};
            int valread = read( new_socket , buffer, 1024);
            cout <<"Data received "<< valread <<" bytes\n";
            cout <<"Saving data to file.\n";            
            myfile << buffer;
            cout <<" File Saved.\n";
        }
};

int main(){
    Server_socket S;
    SUB.Level(easylogger::LEVEL_WARNING);
	SERVER.Level(easylogger::LEVEL_TRACE);
    S.receive_file();
    return 0;
}