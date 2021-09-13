#include "easylogger.h"
#include "template_functions.cpp"

using namespace std;

static easylogger::Logger TEST("TEST");
static easylogger::Logger NETWORK("NETWORK");
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

int main() {
	SUB.Level(easylogger::LEVEL_WARNING);
	NETWORK.Format("[%F:%C %P] %N: %S");
	NETWORK.Level(easylogger::LEVEL_TRACE);
	TRACER.Level(easylogger::LEVEL_TRACE);

	//EASY_LOG(TRACE, main);

	test1();
	test2();

	// add ints
	int a = 10, b = 20, result;
    result = sum <int> (a, b);
    LOG_INFO(TEST, "result = " << result);

	LOG_INFO(SUB, "info!");
	LOG_ERROR(SUB, "error!");
	//LOG_FATAL(TEST, "dead");
	//LOG_ERROR(TEST, "won't see me");
 	char c = getchar();
	return 0;
}
