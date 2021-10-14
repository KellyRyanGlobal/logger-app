#!/usr/bin/env bash

main() {

    if [[ "$1" == "ubuntu" ]]; then
        make -C src
        mkdir -p input output        
        sleep 5        
        ./server.exe &
        ./test_client.exe
    elif [[ "$1" == "alpine" ]]; then
        make -C src
        mkdir -p input output
        sleep 5
        ./server.exe &
        ./test_client.exe  
    else
        echo " Host was not passed as a param (see config)"
        return 1
    fi
    return 0

}


main "$@"