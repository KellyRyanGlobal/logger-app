#include "easylogger.h"
#include "template_functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <cstring>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>


using namespace std;

static easylogger::Logger TEST("TEST");
static easylogger::Logger NETWORK("NETWORK");
static easylogger::Logger HOST("HOST");
static easylogger::Logger TRACER("TRACE");
static easylogger::Logger SUB("SUB", TEST);

static void test1() {
	LOG_TRACE(TRACER, test1);

	LOG_INFO(TEST, "Hi!" << 42);
}

static void test2() {
	//EASY_TRACE(TRACE, test1);

	LOG_DEBUG(TEST, "don't show me");
	LOG_DEBUG(NETWORK, "network");
}

static void add_test() {
	// add ints
	int a = 10, b = 20, result;
    result = sum <int> (a, b);
    LOG_INFO(TEST,  a << " + " << b << " = " << result);
}

void host_test(int hostname) { //This function returns host name for

   if (hostname == -1) {
      perror("gethostname");
      exit(1);
   }
}

void check_host_entry(struct hostent * hostentry) { //find host info from

   if (hostentry == NULL) {
      perror("gethostbyname");
      exit(1);
   }
}
void IP_formatter(char *IPbuffer) { //convert IP string to dotted decimal

   if (NULL == IPbuffer) {
      perror("inet_ntoa");
      exit(1);
   }
}

int main(int argc , char *argv[]) {

    char host[256];
    char output[12] = "hostname: ";
    char *IP;
    struct hostent *host_entry;
    int hostname;

	SUB.Level(easylogger::LEVEL_WARNING);
	NETWORK.Format("[%F:%C %P] %N: %S");
	NETWORK.Level(easylogger::LEVEL_TRACE);
	TRACER.Level(easylogger::LEVEL_TRACE);

	//EASY_LOG(TRACE, main);

	test1();
	test2();
	add_test();

    hostname = gethostname(host, sizeof(host));
	host_test(hostname);
	strcat(output, host);
    LOG_INFO(HOST, output);

	LOG_INFO(SUB, "info!");
	LOG_ERROR(SUB, "error!");
	//LOG_FATAL(TEST, "dead");
	//LOG_ERROR(TEST, "won't see me");

 	char c = getchar();
	return 0;
}
