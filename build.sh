#!/bin/sh

make -C src
mkdir input output
./server.exe &
./test_client.exe