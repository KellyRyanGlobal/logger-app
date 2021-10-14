#!/bin/sh

make -C src
mkdir -p input output
/app/server.exe &
/app/test_client.exe