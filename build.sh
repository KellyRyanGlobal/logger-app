#!/bin/sh

make -C src
pwd
ls -l
chmod +x server.exe
chmod +x test_client.exe
mkdir -p input output
./server.exe &
./test_client.exe