#!/usr/bin/env bash

main() {

    if [[ -z $1  ]]; then        
        echo " Host was not passed as a param (see config)"
        return 1        
    else
        make -C src
        mkdir -p input output        
        sleep 5        
    fi
    return 0

}


main "$@"