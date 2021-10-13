all: docs test-bin server-bin

test-bin: test_client.cc easylogger.h easylogger-impl.h Makefile
	g++ -g -o test-bin test_client.cc
	g++ test_client.cc -o test_client.exe
	mv test_client.exe ..
	# ./test-bin

server-bin: server.cc easylogger.h easylogger-impl.h  Makefile 
	g++ -g -o server-bin server.cc
	g++ server.cc -o server.exe
	mv server.exe ..

docs:
	doxygen

clean:
	rm -f test-bin
	rm -f server-bin
	rm -f *.exe