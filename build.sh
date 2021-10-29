#!/usr/bin/env bash

main() {

    if [[ -z $1  ]]; then        
        echo " Host was not passed as a param (see config)"
        return 1        
    else
        rm -rf input
    	rm -rf output
        make -C src
        mkdir -p input output        
        sleep 5        
        ./server.exe &
        ./test_client.exe
    fi
    return 0

}


main "$@"