#!/usr/bin/env bash

set -e
set -o pipefail


source $HOME/testing-app/test/common.sh


TEST_CHECK=0

main () {
    echo "reading in $1 "
    IFS=$'\r\n' command eval 'results=($(cat $1))'

    echo "Check logic of application"
    sum=$( expr "10" + "20")
    logging_test $sum

    
    echo "Check the system hostname"
    name=$(hostname)

    logging_test $name


    if [[ "$TEST_CHECK" -gt "0" ]]; then
        echo " Test had $TEST_CHECK Failures"
        return 1
    else
        return 0
    fi

}
main "$@"