#!/bin/sh

make -C src
mkdir input output  >/dev/null 2>$1
./server.exe &
./test_client.exe