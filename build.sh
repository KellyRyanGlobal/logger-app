#!/bin/sh

make -C src
pwd
ls -l
cat build.sh
mkdir -p input output
$(pwd)/server.exe &
$(pwd)/test_client.exe