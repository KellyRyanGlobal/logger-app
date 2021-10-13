#!/bin/sh

make -C src
mkdir -p input output
$(pwd)/server.exe &
$(pwd)/test_client.exe