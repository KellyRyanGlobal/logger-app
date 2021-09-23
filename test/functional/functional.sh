#!/usr/bin/env bash

set -e
set -o pipefail

source $HOME/testing-app/test/common.sh

TEST_CHECK=0

main() {

    echo "reading in $1 "
    IFS=$'\r\n' command eval 'results=($(cat $1))'

    echo "Check if not null"
    not_empty $results
    echo "Check for network_test"
    net="NETWORK"
    logging_test $net

    if [[ "$TEST_CHECK" -gt "0" ]]; then
        echo " Test had $TEST_CHECK Failures"
        return 1
    else
        return 0
    fi

}

main "$@"
