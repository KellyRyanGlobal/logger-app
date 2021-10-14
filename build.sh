#!/bin/sh

make -C src
mkdir -p src/input src/output
src/server.exe &
src/test_client.exe