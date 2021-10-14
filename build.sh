#!/bin/sh

main() {
    if [[ $1 == "ubuntu" ]]; then
    {
        make -C src
        mkdir -p src/input src/output
        src/server.exe &
        src/test_client.exe
        return 0
    }
    if [[ $1 == "alpine "]]; then
    {
        make -C src
        mkdir input output
        ./server.exe &
        ./test_client.exe    
        return 0
    }
    else
        echo " Host was not passed as a param (see config)"
        return 1
    fi
}

main "$@"