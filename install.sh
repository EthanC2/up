#!/bin/bash

set -e

if [ "$EUID" -ne 0 ]; then
    >&2 echo 'This script requires root permissions to install.'
    exit 1
fi

make
cp ./up /usr/local/bin
