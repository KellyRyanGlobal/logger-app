#!/bin/sh

make -C src
./server.exe &
./test_client.exe