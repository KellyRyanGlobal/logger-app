#!/bin/sh

make -C src
pwd
ls
mkdir -p input output
./server.exe &
./test_client.exe