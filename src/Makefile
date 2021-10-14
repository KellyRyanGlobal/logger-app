all: docs test-bin server-bin

test-bin: test_client.cc easylogger.h easylogger-impl.h Makefile
	$(CXX) -g -o test-bin test_client.cc
	$(CXX) test_client.cc -o test_client.exe
	mv test_client.exe ..
	# ./test-bin

server-bin: server.cc easylogger.h easylogger-impl.h  Makefile 
	$(CXX) -g -o server-bin server.cc
	$(CXX) server.cc -o server.exe
	mv server.exe ..

docs:
	doxygen

clean:
	rm -f *-bin
	rm -f *.exe	