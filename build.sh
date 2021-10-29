#!/usr/bin/env bash

main() {

    if [[ -z $1  ]]; then        
        echo " Host was not passed as a param (see config)"
        return 1        
    else
        
        mkdir -p input output
        sleep 5  
        
        make -C src && echo "Build successful" || echo "Build Failed" && return 1
          
        # adding in 5 seconds in case system is slow    
         
    fi
    return 0
}


main "$@"