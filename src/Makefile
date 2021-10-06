all: docs test-bin server-bin client-bin

test-bin: test.cc easylogger.h easylogger-impl.h Makefile
	$(CXX) -g -o test-bin test.cc
	$(CXX) test.cc -o test.exe
	mv test.exe ..
	./test-bin

server-bin: server.cc easylogger.h easylogger-impl.h  Makefile 
	$(CXX) -g -o server-bin server.cc
	$(CXX) server.cc -o server.exe
	mv server.exe ..

client-bin: client.cc easylogger.h easylogger-impl.h client.cc Makefile
	$(CXX) -g -o client-bin client.cc
	$(CXX) client.cc -o client.exe
	mv client.exe ..
docs:
	doxygen

clean:
	rm -f test-bin
	rm -f server-bin
	rm -f client-bin
	rm -f *.exe