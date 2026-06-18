#!/bin/bash

if [ $# -ne 1 ]
then
    echo "Uzycie: $0 plik"
    exit 1
fi

if [ ! -f "$1" ]
then
    echo "Podany argument nie jest plikiem"
    exit 2
fi

grep -oE 's[0-9]{5}' "$1"