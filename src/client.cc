// Client side C/C++ program to demonstrate Socket programming
#include "easylogger.h"
#include "template_functions.h"
#include <stdio.h>
#include <sys/socket.h>
#include <fstream>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>


#define PORT 8081

using namespace std;

static easylogger::Logger HOST("HOST");

void streamfiles( void );

int main(int argc, char const *argv[])
{
    int sock = 0, valread;
    struct sockaddr_in serv_addr;
    char *hello = "Hello from client";
    std::string mystring;
    char buffer[1024] = {0};
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("\n Socket creation error \n");
        return -1;
    }
   
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
       
    // Convert IPv4 and IPv6 addresses from text to binary form
    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0) 
    {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }
   
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        printf("\nConnection Failed \n");
        return -1;
    }
    send(sock , hello , strlen(hello) , 0 );
    printf("Hello message sent\n");
    valread = read( sock , buffer , 1024);
    printf("%s\n",buffer );
    system("./test.exe > results.txt");
    std::ifstream myresult ("results.txt");
    pclose(fp);

    return 0;
}
void streamfiles( void )
{

}