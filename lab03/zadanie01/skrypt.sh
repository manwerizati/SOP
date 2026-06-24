#!/bin/bash

KATALOG="$HOME/Documents"

if [ ! -d "$KATALOG" ]; then
    echo "Katalog nie istnieje"
    exit 1
fi

find "$KATALOG" -type f -name "*.txt"