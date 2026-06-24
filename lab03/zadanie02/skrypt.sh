#!/bin/bash

KATALOG="$HOME/Documents"
BACKUP_DIR="$HOME/Documents/.backups"

mkdir -p "$BACKUP_DIR"

DATE=$(date +"%Y-%m-%d_%H-%M")
USER_NAME=$(whoami)

TXT_FILES=$(find "$KATALOG" -type f -name "*.txt")

if [ -z "$TXT_FILES" ]; then
    echo "Nie znaleziono plikow"
    exit 1
fi

tar -czf "$BACKUP_DIR/${USER_NAME}_backup_${DATE}.tar.gz" $TXT_FILES