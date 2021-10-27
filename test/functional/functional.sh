#!/usr/bin/env bash

set -e
set -o pipefail

source test/common.sh

TEST_CHECK=0

not_empty() {
    count=0
    # count the amount of lines logged
    if [[ -z $1 ]]; then
        log_failure "$1 log is empty"
        echo "FAIL "
        TEST_CHECK=${TEST_CHECK+1}
    else 
        log_success "$1 log was populated"
        echo -e "\n"
    fi        
}

main() {

    echo "reading in $1 "
    IFS=$'\r\n' command eval 'results=($(cat $1))'

    echo "Check if not null"
    not_empty $results
    echo "Check for network_test"
    logging_test "NETWORK"

    if [[ "$TEST_CHECK" -gt "0" ]]; then
        echo " Test had $TEST_CHECK Failures"
        return 1
    else
        return 0
    fi

}

main "$@"
