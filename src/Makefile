all: docs test-bin server-bin client-bin

test-bin: test.cc easylogger.h easylogger-impl.h Makefile
	$(CXX) -g -o test-bin test.cc
	./test-bin

server-bin: server.cc easylogger.h easylogger-impl.h  Makefile 
	$(CXX) -g -o server-bin server.cc

client-bin: client.cc easylogger.h easylogger-impl.h client.cc Makefile
	$(CXX) -g -o client-bin client.cc

docs:
	doxygen

clean:
	rm -f test-bin
