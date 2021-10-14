#!/usr/bin/env bash

set -e
set -o pipefail

source test/common.sh

TEST_CHECK=0

main() {


    echo "Verify Files were built "    
    check_files "test_client.exe"
    check_files "server.exe"

    if [[ "$TEST_CHECK" -gt "0" ]]; then
        echo " Test had $TEST_CHECK Failures"
        return 1
    else
        return 0
    fi
}

main "$@"