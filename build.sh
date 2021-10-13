#!/bin/sh

make -C src
mv src/test_client.exe ..
mv src/server.exe ..
mkdir -p input output
./server.exe &
./test_client.exe