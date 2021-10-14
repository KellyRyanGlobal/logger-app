#!/bin/sh

make -C src
mkdir -p input output
./server.exe &
./test_client.exe