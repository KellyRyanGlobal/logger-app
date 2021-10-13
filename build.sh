#!/bin/sh

make -C src
pwd
ls -l
cat build.sh
mkdir -p input output
./server.exe &
./test_client.exe