#!/bin/bash

BACKUP_DIR="$HOME/Documents/.backups"
LIMIT_MB=1

USED_MB=$(du -m "$BACKUP_DIR" | awk '{print $1}')

if [ "$USED_MB" -gt "$LIMIT_MB" ]; then
    echo "${USED_MB} MB (limit ${LIMIT_MB} MB)"

    echo "limit: ${USED_MB} MB" | mail -s "backup alert" "$(whoami)"
fi