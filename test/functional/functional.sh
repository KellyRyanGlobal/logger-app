#!/usr/bin/env bash

set -e
set -o pipefail

source test/common.sh

TEST_CHECK=0

main() {

    echo "reading in $1 "
    IFS=$'\r\n' command eval 'results=($(cat $1))'

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
